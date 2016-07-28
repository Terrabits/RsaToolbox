
from general import files_excluding

root  = '..\\Source'
file_ignores = ['*.h', '*.cpp']
directory_ignores = ['..\\Source\\Instruments']
for file in files_excluding(root, file_ignores, directory_ignores):
    print(file)