from general import *


this_path   = os.path.dirname(os.path.abspath(__file__))
source_path = os.path.join(this_path, '..\\Install')
destination = os.path.join(this_path, '..\\_install')

files = files_excluding(source_path, [], [])
copy_files(files, source_path, destination)

