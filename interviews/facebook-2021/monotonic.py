'''
An array is monotonic if it is either monotone increasing or monotone decreasing.
'''

def monotonic(A):
    increasing = decreasing = True
    for i in range(len(A) - 1):
        if A[i] > A[i+1]:
            increasing = False
        if A[i] < A[i+1]:
            decreasing = False
    return increasing or decreasing

for i in [[0], [5], [1,2], [2,2], [3,2,1], [1,4,2,3], [9,8,15], [5,6,7,8,9], [11,12,13,14]]:
    print("is {} monotonic? {}".format(i, monotonic(i)))