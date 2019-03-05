import re
import mock
import pytest

input_string = "-5b34 +2b90 +7b20 +5b10"

'''TODO
while len(input_string) > 3:
	input_string = raw_input("Enter a string expression: ")
validate input by regex match for no leading/trailing spaces
unit tests
'''

def get_total_weight(input):
	total_weight = 0
	boxes = input.split(' ')
	for box in boxes:
		g = re.compile("(\+|\-)([0-9]+)b([0-9]+)").search(box)
		'''
		0: full expression
		1: + or -
		2: number of boxes
		3: box weight
		'''
		if g.group(1) == "+":
			total_weight += int(g.group(2)) * int(g.group(3))
		else:
			total_weight -= int(g.group(2)) * int(g.group(3))
	return total_weight

# python -m pytest box-weight.py
def test_get_total_weight():
	with mock.patch('__builtin__.raw_input', return_value="sample_expression"):
		assert get_total_weight() == "tentative"

if __name__ == "__main__":
	print("The total weight of the boxes is {0}".format(get_total_weight(input_string)))



