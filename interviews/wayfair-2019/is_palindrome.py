'''
Check if a string is a palindrome. Ignore all special characters, whitespace, numbers
'''
#!/usr/bin/env python2.7
import re
import mock
import pytest

def is_palindrome():
    input_string = raw_input("Enter a string to check for palindrome: ") 
    input_string = re.sub('[^a-zA-Z]+','',input_string)
    input_string = input_string.lower() # case_fold() is python3
    reverse_string = ''.join(reversed(input_string))  
    if (input_string is None) or not (input_string):
        return "invalid"
    if input_string == reverse_string:
        return "is a palindrome"
    else:
        return "not a palindrome"

# python -m pytest is_palindrome.py
# raw_input, __built_in__ are python2.7+
def test_is_palindrome():
    with mock.patch('__builtin__.raw_input', return_value=""):
        assert is_palindrome() == "invalid"
    with mock.patch('__builtin__.raw_input', return_value="   "):
        assert is_palindrome() == "invalid"
    with mock.patch('__builtin__.raw_input', return_value="  ? . , "):
        assert is_palindrome() == "invalid"
    with mock.patch('__builtin__.raw_input', return_value="racecar"):   
        assert is_palindrome() == "is a palindrome"
    with mock.patch('__builtin__.raw_input', return_value="rAce Car"):
        assert is_palindrome() == "is a palindrome"
    with mock.patch('__builtin__.raw_input', return_value="race c$ar?"):
        assert is_palindrome() == "is a palindrome"
    with mock.patch('__builtin__.raw_input', return_value="racecarwrong"):
        assert is_palindrome() == "not a palindrome"
    with mock.patch('__builtin__.raw_input', return_value="@ra$cecarWrong"):
        assert is_palindrome() == "not a palindrome"

if __name__ == "__main__":
    print is_palindrome()
    #test_is_palindrome()

'''
Time complexity is O(n). Worst case O(n^2) because of reversed() and join()
Space complexity is O(n)

INTERVIEW:

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

What happens when you write to the database at the same time?
https://stackoverflow.com/questions/64517440/in-databases-is-row-level-locking-an-example-of-acid-optimistic-concurrency-o  
https://stackoverflow.com/questions/13087197/what-happens-when-multiple-simultaneous-update-requests-received-for-a-sql-table/13087311#13087311  
https://stackoverflow.com/questions/32087233/how-does-mysql-handle-concurrent-inserts  
https://www.postgresql.org/docs/9.1/explicit-locking.html  

Design a SQL schema for movies with movie titles, genre, actors, year

Find all movies in the comedy genre that do not contain the actor Adam Sandler in them

> SELECT m.titles FROM movies AS m 
INNER JOIN actors AS a ON m.actor_id = a.id 
INNER JOIN genres AS g ON m.genre_id = g.id 
WHERE m.genre_id = 1 AND 
m.actor_id NOT IN (SELECT a.id FROM actors AS a WHERE a.name = 'Adam Sandler' LEFT OUTER JOIN genres AS g ON a.genre_id = genre.id)

Design a tweet url shortener service with high load
'''
