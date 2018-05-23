#!/usr/bin/env python
import os

def main(prompt):
  filename = raw_input(prompt) #ask for filename using the given prompt
  if(os.path.exists(filename)):
    for line in open(filename, "r").readlines(): 
    	print line
  else:
    print "The file you selected does not exist, please try again"
    main(prompt) #Repeat this function if the use did not give valid input

raw_input("Press enter to transfer the files...")

if __name__ == "__main__":
    main("Select file in current directory:")

# TODO add test cases