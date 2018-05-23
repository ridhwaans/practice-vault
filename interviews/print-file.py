#!/usr/bin/env python
import os

'''Print file
'''
def main(prompt):
  filename = raw_input(prompt) #ask for filename using the given prompt
  if validate(filename):
    for line in open(filename.strip(), "r").readlines(): 
        print line
  else:
    print "The file you selected does not exist, please try again"
    main(prompt) #repeat this function if the use did not give valid input

def validate(input):
    input = input.strip()
    if input is None:
        return False
    elif input == '':
        return False
    elif not (os.path.exists(input)):
        return False
    else:
        return True

if __name__ == "__main__":
    main("Select file in current directory:")
