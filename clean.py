import sys
import os
from scripts.general import delete_all_except_keep

args = [arg.lower() for arg in sys.argv]

# Paths
clean_root   = os.path.dirname(os.path.abspath(__file__))
build_path   = os.path.join(clean_root, '_build')   + os.path.sep
install_path = os.path.join(clean_root, '_install') + os.path.sep

# clean _install
if "--skip-build" not in args:
    delete_except(build_path,   ['.keep'])

if "--skip-install" not in args:
    delete_except(install_path, ['.keep'])
