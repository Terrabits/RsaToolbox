
from scripts.general import *

# Basic paths
project_root = os.path.dirname(os.path.abspath(__file__))
destination  = os.path.join(project_root, '_install')

# Copy Install folder contents
install_excludes = ['*.keep']
install_path  = os.path.join(project_root, 'Install')
install_files = files_excluding(install_path, install_excludes)
copy_files(install_files, install_path, destination)

# Copy Includes (*.h)
include_globs    = ['*.h']
sourcecode_path  = os.path.join(project_root, 'Source')
include_files = included_files(sourcecode_path, include_globs)
destination_include_path = os.path.join(destination, 'Include')
copy_files(include_files, sourcecode_path, destination_include_path, preserve_structure=False)

# Copy Library
library_globs    = ['*.dll','*.lib','*.a','*.so']
build_path = os.path.join(project_root, '_build')
destination_library_path = os.path.join(destination, 'Library')
files = included_files(sourcecode_path, library_globs)
copy_files(files, sourcecode_path, destination_library_path, preserve_structure=False)

files = included_files(build_path, library_globs)
copy_files(files, build_path, destination_library_path, preserve_structure=False)

# Process documentation
# RUN DOXYGEN
documentation_path = os.path.join(project_root, 'Documentation')
documentation_globs = ['*.qch']
documentation_destination = os.path.join(destination, 'QtCreator')
documentation_destination = os.path.join(documentation_destination, 'Documentation')
qch_files = included_files(documentation_path, documentation_globs)
copy_files(qch_files, documentation_path, documentation_destination, preserve_structure=False)

# Qt Creator templates
# Left as an exercise :-)