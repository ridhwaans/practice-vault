'''
Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.

Note:

The name of a file contains at least a period and an extension.

The name of a directory or sub-directory will not contain a period.
'''

'''
Assumptions:
1) The longest absolute path can be a single file in the root level without subdirectories
2) The extension of the file does not necessarily have to be .ext
'''
import re

def longestAbsolutePath(string):
    longest = None
    paths = re.compile(r'\.[a-zA-Z0-9]{2,4}').split(string)
    for path in range(0,len(paths)):
        print paths[path]
        special = re.search(r'(\\n(\\t)*)',paths[path])
        print special
        valid = True
        if len(special.groups()) > 1:
            index = 0
            while valid is True:
                if (index > 0) and (special.groups(index) == special.groups(index-1) + '\\t'):
                    valid = True
                else:
                    valid = False
                index += 1
        else:
            if special.group(0) != '\\n':
                valid = False
        if valid == False:
            paths.pop(path)
        else:
            paths[path] = re.sub(r'\\n(\\t)*','/', paths[path])
            if (longest is None or longest < len(paths[path])):
                longest = paths[path]
    return longest


input_string = r'dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext'
print "Given {0}\n The longest absolute path is {1}".format(input_string, longestAbsolutePath(input_string))