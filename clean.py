import os
import shutil

[root, dirs, files] = next(os.walk('./_build/'))
for dir in dirs:
    dir = os.path.join(root, dir)
    shutil.rmtree(dir)
for file in files:
    if file == ".keep":
        break;
    file = os.path.join(root, file)
    shutil.rmfile(file)
    
exit(0)