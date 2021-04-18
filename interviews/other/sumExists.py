'''
This question was asked by interviewing.io
Given an array of integers, check if any sum of numbers can equal to a target sum

target: 7
nums [5,3,4,7] 
True

target: 7
nums [4,2]
False

target: 7
nums [1] 1+1+1+1+1+1+1
True

Assumptions: 
no negative numbers
duplicates are allowed
array is not sorted
'''

def sumExists(nums, target):
    return sumHelper(nums, target, 0, {})
    
    
def sumHelper(nums, target, current_sum, cached_results):
    if current_sum == target:
        return True
    if current_sum > target: 
        return False
    
    if current_sum in cached_results:
        return cached_results[current_sum]
    
    for num in nums:
        result = sumHelper(nums, target, current_sum + num, cached_results)
        cached_results[current_sum] = result
        if result: 
           return True
    return False

print(sumExists([5,3,4,7], 7))
print(sumExists([4,2], 7))
print(sumExists([1], 7))

# Comeplexity
# time O(n^m)
# space O(m)

# Complexity after memoization
# time O(n*m)
# space O(m) 

# https://start.interviewing.io/interview/2upo7daBR84D/replay
