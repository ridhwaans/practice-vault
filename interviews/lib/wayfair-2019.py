'''
Check if a string is a palindrome. Ignore all special characters, whitespace, numbers
'''
import re
import mock
import pytest

def isPalindrome():
    input_string = raw_input("Enter a string to check for palindrome: ") #raw_input is python2.7+ only
    input_string = re.sub('[^a-zA-Z]+','',input_string)
    input_string = input_string.lower() # case_fold() is python3
    reverse_string = ''.join(reversed(input_string))  
    if (input_string is None) or not (input_string):
        return "empty"
    if input_string == reverse_string:
        return "is a palindrome"
    else:
        return "not a palindrome"

# python -m pytest wayfair-2019.py
def test_isPalindrome():
    with mock.patch('__builtin__.raw_input', return_value=""):
        assert isPalindrome() == "empty"
    with mock.patch('__builtin__.raw_input', return_value="   "):
        assert isPalindrome() == "empty"
    with mock.patch('__builtin__.raw_input', return_value="  ? . , "):
        assert isPalindrome() == "empty"
    with mock.patch('__builtin__.raw_input', return_value="racecar"):   
        assert isPalindrome() == "is a palindrome"
    with mock.patch('__builtin__.raw_input', return_value="rAce Car"):
        assert isPalindrome() == "is a palindrome"
    with mock.patch('__builtin__.raw_input', return_value="race c$ar?"):
        assert isPalindrome() == "is a palindrome"
    with mock.patch('__builtin__.raw_input', return_value="racecarwrong"):
        assert isPalindrome() == "not a palindrome"
    with mock.patch('__builtin__.raw_input', return_value="@ra$cecarWrong"):
        assert isPalindrome() == "not a palindrome"

'''
https://stackoverflow.com/a/3987107/3577482
'''
if __name__ == "__main__":
    isPalindrome()
    #test_isPalindrome()

'''
SQL exercises:
List departments which do not have employees in them

> SELECT d.name FROM departments AS d LEFT OUTER JOIN employees AS e on d.id = e.department_id WHERE e.department_id IS NULL

Count the number of employees for each salary bracket

> SELECT 
    CASE
        WHEN salary BETWEEN 0 AND 10000 THEN "Group 1"
        WHEN salary BETWEEN 10001 AND 20000 THEN "Group 2"
        WHEN salary BETWEEN 20001 AND 30000 THEN "Group 3"
        WHEN salary BETWEEN 30001 AND 40000 THEN "Group 4"
        WHEN salary BETWEEN 40001 AND 50000 THEN "Group 5"
    END AS salary_group, count(*) AS employees_count
from employees group by salary_group
'''