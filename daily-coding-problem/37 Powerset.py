"""
The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.
"""

def get_power_set_helper(power_set, input_set, k):
    if k == len(input_set):
        print(power_set)
    else:
        power_set[k] = None
        get_power_set_helper(power_set, input_set, k+1)
        power_set[k] = input_set[k]
        get_power_set_helper(power_set,input_set,k+1)

def get_power_set(input_set):
    power_set = len(input_set) * [None]
    get_power_set_helper(power_set,input_set,0)

get_power_set([1,2,3,4,5,6,7,8,9,10])