'''
find_pair.py: Finds the pair of items with the closest matching price to the balance in the gift card

Assumptions: 
1) There are no duplicate items
2) Prices are always a positive integer
3) There is no zero price item
4) Given list in file is sorted, comma separated
5) List has at least two lines of items
6) There are no signs or decimals in the price list
7) Balance on the gift card should not be zero

Question: What is the big-O notation for your program?

ANSWER: O(n)

Question: How would you optimize your solution if you could not load the file in memory?

ANSWER: If the file is too large for the memory operation,  
1) scale up the local machine (ram, cpu)  
2) compress the representation of data in memory  
3) chunking, loading all data one chunk at a time  
4) index and summarize the data when you need different subsets at different times  
Source: https://pythonspeed.com/articles/data-doesnt-fit-in-memory/
'''
import os
import sys  
import argparse  
import operator

def find_pair(prices, size, target_price): 
    # Initialize left and right variables
    MAX_VAL = sys.maxint
    pair_l, pair_r = 0, 0
    l, r, diff = 0, size-1, MAX_VAL 
      
    while l < r: 
        # Check if closest pair 
        if (abs(prices[l] + prices[r]) - target_price) < diff: 
            pair_l = l 
            pair_r = r 
            diff = abs((prices[l] + prices[r]) - target_price) 
        # If current pair has a greater sum, move to lesser values
        if prices[l] + prices[r] > target_price:  
            r -= 1
        else: 
            l += 1
    # Get indexes of closest pair
    return (pair_l, pair_r)

def main():
    parser = argparse.ArgumentParser(description="find_pair:")
    parser.add_argument("prices", type=validate_prices, help="A filename with a list of sorted prices")
    parser.add_argument("target_price", type=validate_target_price, help="The balance of your gift card (truncates decimals)")
    args = parser.parse_args()
    items = []
    with open(args.prices) as f:
        for line in f:
            (key, val) = line.split(',')
            val = int(val.rstrip("\n\r"))
            items.append((key, val))
    '''
    NOTE: before python 3.6, dictionaries in python were unordered
    they're still not ordered in python 3.6+, but they remember what order the key-value pairs were inserted
    https://stackoverflow.com/questions/39980323/are-dictionaries-ordered-in-python-3-6
    alternative option is an OrderedDict or a list of tuples (name, price) sorted by price
    '''
    (item1, item2) = find_pair(map(operator.itemgetter(1), items), len(items), args.target_price)
    print('The closest pair is {} and {}'.format(
        (items[item1][0] + ' $' + str(items[item1][1])), 
        (items[item2][0] + ' $' + str(items[item2][1]))
        ))

def validate_target_price(value):
    try:
        value = int(float(value))
    except ValueError:
        raise argparse.ArgumentTypeError("{0} is not a valid number".format(value))

    if value <= 0:
        raise argparse.ArgumentTypeError("{0} should be a non zero integer".format(value))
    else:
        return value
    
def validate_prices(value):
    if value.strip() == '':
        raise argparse.ArgumentTypeError("{0} is an invalid filename".format(value))
    elif not (os.path.exists(value)):
        raise argparse.ArgumentTypeError("{0} does not exist".format(value))
    else:
        return value

if __name__ == "__main__":
    main()

'''
Time complexity is O(n)
'''