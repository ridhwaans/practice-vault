'''
Given a list of integers which contains pairs of duplicates, implement a data structure and algorithm which finds the non-duplicate number
'''
def find_unique(items):
    num_count = {}
    for item in items:
        if not item in num_count:
            num_count[item] = 1
        else:
            num_count[item] += 1
    for num, count in num_count.items(): # dictionary.iteritems():  (for Python 2.x)
        if count == 1:
            return num
    return -1


print find_unique([2,3,4,5,6,6,7,7,2,2,2,5,5,3,4])  

'''
Time complexity is O(n)
Space complexity is O(n)
'''