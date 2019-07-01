'''
Given a log file with one message per line, find the top three occurring log messages
Assumptions:
- no blank or empty lines
- no timestamp or line prefix
- messages are case insensitive
'''
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
        with open(addr, 'r') as file:
            for line in nonblank_lines(file):
                lines.append(line.lower())
        print "The top three occurring log messages are: \n"
        for item in Counter(lines).most_common(3):
            print "message: {0}, frequency: {1}".format(item[0],item[1])
    except Exception, e:
        print("An error occurred {0}".format(e))

if __name__ == "__main__":
    main()


