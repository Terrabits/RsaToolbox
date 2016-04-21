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
        for file in files:
            file = os.path.join(root, file)
        for ignore in file_ignores:
            excludes = fnmatch.filter(files, ignore)
            for excluded_file in excludes:
                files.remove(excluded_file)
        matches.append(files)
    return matches



def delete_except(path, file_ignores):
    directory_ignores = [os.path.relpath(d, path) for d in directory_ignores]
    for d in directory_ignores:
        directory_ignores.append(subdirs_join_path(d))
    for root, dirs, files in os.walk(path):
        for dir in dirs:
            dir = os.path.join(root, dir)
            shutil.rmtree(dir)
        for file in files:
            if fnmatch(file, file_ignores):
                continue
            file = os.path.join(root, file)
            os.remove(file)


def copy_files(files, destination, preserve_structure=True):
    if preserve_structure:
        for file in files:
            dirname = os.path.dirname(file)
            if not os.path.exists(dirname):
                os.makedirs(dirname)
            shutil.copyfile(file, os.path.join(destination, file))
    else:
        for file in files:
            shutil.copy(file, destination)

def delete_files(files):
    for file in files:
        os.remove(file)

def delete_directories(dirs):
    for d in dirs:
        shutil.rmtree(d)

def subdirs_join_path(path):
    catalog = []
    for root, dirs, files in os.walk(path):
        for d in dirs:
            catalog.append(os.path.join(path, d))
    return catalog

def remove_paths(files):
    return [os.path.basename(file) for file in files]