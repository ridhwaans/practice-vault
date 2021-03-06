'''
Find all permutations of a list of letters
'''
from collections import Counter

letters = ['A','B','C']
def permuteUnique(letters):
    def btrack(path, counter):
        if len(path)==len(letters):
            ans.append(path[:])
        for x in counter:  # dont pick duplicates
            if counter[x] > 0:
                path.append(x)
                counter[x] -= 1
                btrack(path, counter)
                path.pop()
                counter[x] += 1
    ans = []
    btrack([], Counter(letters))
    return ans

print(permuteUnique(letters))

'''
Time complexity is O(n*n!). There are n! permutations and O(n) to print a permutation
Space complexity is O(n)

See also:
https://docs.python.org/3/library/collections.html#collections.Counter

Design a model for a library reservation system to checkout, renew and return books
'''