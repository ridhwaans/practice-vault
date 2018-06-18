"""
cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. 
For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.
"""

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
    
def car(pair):
	def first(cons):
		return a
	return first

def cdr(pair):
	def last(cons):
		return b
	return last


print "car(cons(3, 4)) is {0}".format(car(cons(3,4)))
print "cdr(cons(3, 4)) is {0}".format(cdr(cons(3,4)))

# FUNCTIONS

# Rename_files
# Search and replace filesnames in directory using regex
# Usage: rename /my/folder/* 
# 				(^(0[1-9]|1[0-2])(0[1-9]|1[0-9]|2[0-9]|3[0-1])(2018)\s(\w+))(\.\w+$)
# 				(^(0[1-9]|1[0-2])(0[1-9]|1[0-9]|2[0-9]|3[0-1])(18)\s(\w+))(\.\w+$)
rename_files() {
    for file in {$1}*
	do
	    if [ -f "$file" ]
	    then
	          sed 's/(^(0[1-9]|1[0-2])(0[1-9]|1[0-9]|2[0-9]|3[0-1])(2018)\s(\w+))(\.\w+$)/(^(0[1-9]|1[0-2])(0[1-9]|1[0-9]|2[0-9]|3[0-1])(18)\s(\w+))(\.\w+$)/g' "$file"
	    fi
	done
}