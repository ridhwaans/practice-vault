'''
Design Amazon's drone delivery system where you want to carry as many packages as possible under a weight limit. 
'''
'''
Assumptions:
- Weight is a positive integer
- Each item has a price and a weight
- Total weight limit is a positive amount
- Want to maximize quantity of packages to fit, not necessarily the heaviest items
- Cannot have fractions, only include or exclude items
'''
class Package():
    def __init__(self, weight, price):
        self.weight = weight
        self.price = price

def maxPackages(prices, weights, target_weight):
    if len(prices) != len(weights):
        return 0
    maxPackagesHelper(prices, weights, target_weight, 0, {})
   
def maxPackagesHelper(prices, weights, target_weight, current, mem):
    #print weights[current], prices[current], target_weight, current
    if current == len(weights):
        return 0
    if weights[current] > target_weight:
        result = maxPackagesHelper(prices, weights, target_weight, current+1, mem)
    result = min(
        (maxPackagesHelper(prices, weights, target_weight - weights[current], current+1, mem) + prices[current]),
        maxPackagesHelper(prices, weights, target_weight, current+1, mem))

    mem[current] = result
    return result

packages = []
for i in range(1,10):
    packages.append(Package(i, i))
    
print "answer is {}".format(maxPackages([p.price for p in packages], [p.weight for p in packages], 7))