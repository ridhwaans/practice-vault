'''
Given list of integers, assume sorted or unsorted, find the largest three elements
'''
import random
def largest_three(numbers):
    first, second, third = None, None, None
    temp = None
    for i in numbers:
        if i > first:
            temp = third
            third = second
            second = first
            first = i
        if i > second and i < first:
            temp = third
            third = second
            second = i
        if i > third and i < second:
            temp = third
            third = i
    return [first, second, third]

test_cases = ([8,3,4,54,32,1,2,99,32], [1,2,3], [234,65,34,-1,34,23,98])
numbers = random.sample(range(0, 100), 10)
print '\n'.join('the largest three in {0} are: {1}'.format(x, largest_three(x)) for x in test_cases)

'''
Time complexity is O(n)
Space complexity is O(1)
'''