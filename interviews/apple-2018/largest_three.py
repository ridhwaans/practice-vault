'''
Given list of integers, assume sorted or unsorted, find the largest three elements
'''
def largest_three(numbers):
    first, second, third = None, None, None
    for i in numbers:
        if i > first:
            third = second
            second = first
            first = i
    print 'three largest in {0} are: {1}'.format(numbers, (first, second, third))

largest_three([8,3,4,54,32,1,2,99,32]) 

