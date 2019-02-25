'''
Check if a string is a palindrome. Ignore all special characters, whitespace, numbers
TODO
Defensive programming/graceful handling
unit tests
'''
import re

input_string = "racecar"
input_string = input_string.case_fold()
input_string = re.sub('[^a-zA-Z]+','',input_string)
reverse_string = ''.join(reversed(input_string))

if input_string == reverse_string:
	print "is a palindrome"
else:
	print "not a palindrome"

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