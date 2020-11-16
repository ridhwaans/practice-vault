"""
Daily Coding Problem: Problem #9

This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
"""

def dcp9(numbers):
    incl, excl = 0, 0
    for num in numbers:
       temp = max(incl, excl)
       incl = num + excl
       excl = temp
    return (max(incl, excl))

numbers = [2, 4, 6, 2, 5]
print(f"Given {numbers}, largest sum of non-adjacent numbers is {dcp9(numbers)}")

'''
Time complexity is O(N)
Space complexity is O(1)
'''