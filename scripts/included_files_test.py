
from general import included_files

root  = '../'
globs = ['*.h','*.cpp']
files = included_files(root, globs)
for file in files:
    print(file)