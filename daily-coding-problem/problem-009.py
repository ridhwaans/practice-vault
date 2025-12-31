"""
Daily Coding Problem: Problem #9

This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
"""

def dcp9(numbers):
    if len(numbers) == 1:
        return numbers[0]
    if len(numbers) == 2:
        return max(numbers[0], numbers[1])

    largest = [None] * len(numbers)
    largest[0] = numbers[0]
    largest[1] = max(numbers[0], numbers[1])
    for i, num in enumerate(numbers):
        if i > 1: 
            largest[i] = max(largest[i-2] + numbers[i], largest[i-1])
    return largest[len(numbers) - 1]

numbers = [2, 4, 6, 2, 5]
print(f"Given {numbers}, largest sum of non-adjacent numbers is {dcp9(numbers)}")
numbers = [5, 1, 1, 5]
print(f"Given {numbers}, largest sum of non-adjacent numbers is {dcp9(numbers)}")

'''
Time complexity is O(N)
Space complexity is O(1)

See also:
https://www.youtube.com/watch?v=xlvhyfcoQa4
'''