import os
import shutil
from glob import iglob
import fnmatch


def included_files(path, globs=['.*','*']):
    matches = []
    for root, dirs, files in os.walk(path):
        for _glob in globs:
            for file in fnmatch.filter(files, _glob):
                file = os.path.join(root, file)
                file = os.path.relpath(file, path)
                matches.append(file)
    return matches

def files_excluding(path, file_ignores, directory_ignores=[]):
    directory_ignores = [os.path.relpath(d, path) for d in directory_ignores]
    matches = []
    for root, dirs, files in os.walk(path):
        root = os.path.relpath(root, path)
        if root in directory_ignores:
            dirs[:] = []
            continue
        files[:] = [os.path.join(root, file) for file in files]
        for ignore in file_ignores:
            excludes = fnmatch.filter(files, ignore)
            for excluded_file in excludes:
                files.remove(excluded_file)
        matches += files
    return matches

# Assume file has relative path to source_dir
def copy_files(files, source_dir, destination_dir, preserve_structure=True):
    if preserve_structure:
        for file in files:
            source_file = os.path.join(source_dir, file)
            destination_file = os.path.join(destination_dir, file)
            dirname = os.path.dirname(destination_file)
            if dirname and not os.path.exists(dirname):
                os.makedirs(dirname)
            shutil.copyfile(source_file, destination_file)
    else:
        for file in files:
            if not os.path.exists(destination_dir):
                os.makedirs(destination_dir)
            file = os.path.join(source_dir, file)
            shutil.copy(file, destination_dir)

def delete_except(path, file_ignores=[], directory_ignores=[]):
    directory_ignores = [os.path.join(path, d) for d in directory_ignores]
    ignores_with_subdirs = []
    for d in directory_ignores:
        ignores_with_subdirs.append(d)
        ignores_with_subdirs += subdirs_join_path(d)
    for root, dirs, files in os.walk(path, topdown=False):
        for d in dirs:
            d = os.path.join(root, d)
            if not samefile_in(d, ignores_with_subdirs) and not os.listdir(d):
                shutil.rmtree(d)
        files = remove_ignored_files(files, file_ignores)
        files = [os.path.join(root, file) for file in files]
        delete_files(files)

def delete_files(files):
    for file in files:
        os.remove(file)

def delete_directories(dirs):
    for d in dirs:
        shutil.rmtree(d)

def samefile_in(file, files):
    for f in files:
        if os.path.samefile(f, file):
            return True
    return False

def subdirs_join_path(path):
    catalog = []
    for root, dirs, files in os.walk(path):
        for d in dirs:
            d = os.path.join(root, d)
            catalog.append(d)
    return catalog

def remove_ignored_files(files, ignores):
    for ignore in ignores:
        ignored_files = fnmatch.filter(files, ignore)
        for file in ignored_files:
            files.remove(file)
    return files

def touch(file):
    with open(file, 'a'):
        os.utime(file, None)