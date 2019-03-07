import re
import mock
import pytest

group_match = r"(\+|-)([0-9]+)b([0-9]+)"
full_match = r"^(?!.*\s$)(" + group_match + r"\s?)+$"

def get_total_weight(input):
    total_weight = 0
    boxes = input.split(' ')
    for box in boxes:
        g = re.compile(group_match).search(box)
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

def main():
    input_string = ""
    match = False
    while (match is False):
        input_string = raw_input('Enter string (i.e. -5b34 +2b90 +7b20 +5b10):')
        if (re.compile(full_match).match(input_string) is None):
            return ("Invalid string. Try again")
            # replace return with print to allow loop
        else:
            match = True
    return ("The total weight of the boxes is {0}".format(get_total_weight(input_string)))

if __name__ == "__main__":
    print(main())
    
''' 
python -m pytest box-weight.py
TODO:
-treat no given sign as positive 
-allow leading/trailing whitespace
-treat no given number as 1 box
'''
def test_raw_input():
    with mock.patch('__builtin__.raw_input', return_value="wrong input"):
        assert main() == "Invalid string. Try again"
    with mock.patch('__builtin__.raw_input', return_value="-110"):
        assert main() == "Invalid string. Try again"
    with mock.patch('__builtin__.raw_input', return_value=" +5b20"):
        assert main() == "Invalid string. Try again"
    with mock.patch('__builtin__.raw_input', return_value="+5b20 "):
        assert main() == "Invalid string. Try again"
    with mock.patch('__builtin__.raw_input', return_value="+5b20  -1b10"):
        assert main() == "Invalid string. Try again"
    with mock.patch('__builtin__.raw_input', return_value="-5b34 +2b90 +7b20 +5b10"):
        assert main() == "The total weight of the boxes is 200"
