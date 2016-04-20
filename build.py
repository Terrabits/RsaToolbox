# Copy as-is:
# - Documentation/Web

# What NOT to copy:
# .py files (ironically)
# *.cpp
# *.user
# _* (but what about documentation?)
# .* (.git, .gitignore)
# *.pri
# *.pro
# Documentation/ # for now



from shutil import *

ignores = []
ignores.append('first.ignore')
ignores.append('second.ignore')
ignores.append('third.ignore')

ignore = ignore_patterns(ignores)
copytree(source, destination, ignore)