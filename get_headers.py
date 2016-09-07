from pathspec import PathSpec

def files_from(path, matches):
    spec = PathSpec.from_lines('gitwildmatch', matches)
    return list(spec.match_tree(path))

headers = files_from('src/', ['*.h'])
for header in headers:
    print(header)
