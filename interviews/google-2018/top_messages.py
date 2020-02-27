'''
Given a log file with one message per line, find the top three occurring log messages
'''
'''
Assumptions:
- no blank or empty lines
- no timestamp or line prefix
- messages are case insensitive
- file can be empty or non existent
'''
import os
import mock
import __builtin__
from collections import Counter 

def nonblank_lines(f):
    for l in f:
        line = l.rstrip()
        if line:
            yield line

def main():
    lines = []
    try:
        addr = raw_input("Enter file:")
        if addr is None:
            raise ValueError
        addr = addr.strip() # trims left and right
        if addr == '':
            raise ValueError
        elif not (os.path.exists(addr)):
            raise IOError # python2 is IOError, python3 is FileNotFoundError
        with open(addr, 'r') as file:
            for line in nonblank_lines(file):
                lines.append(line.lower())
        print "The top three occurring log messages are: \n"
        for item in Counter(lines).most_common(3):
            print "message: {0}, frequency: {1}".format(item[0],item[1])
        return True
    except Exception, e:
        print("An error occurred {0}".format(e))
        return False

if __name__ == "__main__":
    main()

# python -m pytest top_messages.py
# valid: ['top_messages.py']
# invalid: [None, '', 'nonexistent']
def test_01():
    with mock.patch.object(__builtin__, 'raw_input', side_effect=['top_messages.py']):
        assert main() == True

def test_02():
    with mock.patch.object(__builtin__, 'raw_input', side_effect=['  ']):
        assert main() == False

def test_03():
    with mock.patch.object(__builtin__, 'raw_input', side_effect=[None]):
        assert main() == False

def test_04():
    with mock.patch.object(__builtin__, 'raw_input', side_effect=['nonexistent']):
        assert main() == False

'''
> python -m pytest top_messages.py
Time complexity is O(n)
'''