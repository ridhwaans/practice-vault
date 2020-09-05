'''
Design a delivery algorithm where you want to carry as many packages as possible under a weight limit. 

Assumptions:
- Weight is a positive integer
- Each item has a price and a weight
- Total weight limit is a positive amount
- Want to maximize quantity of packages to fit, not necessarily the heaviest items
- Cannot have fractions, only include or exclude items
'''
import numpy as np
class Package():
  def __init__(self, weight, price):
    self.weight = weight
    self.price = price

def maxPackages(prices, weights, target_weight):
  w_sum = 0
  packages = []
  for i,w in sorted(enumerate(weights), key=lambda x: x[1]):
    if w_sum + w > target_weight:
      break
    w_sum += w
    packages.append((i,w))
  return packages

packages = [Package(i,i) for i in np.random.choice(10, 10, replace=True)]
print([p.weight for p in packages])
print("use packages:")
for i,w in maxPackages([p.price for p in packages], [p.weight for p in packages], 10):
  print(f"  package {i} with weight {w}")

"""
Time complexity is O(n)
Space complexity is O(n)
See also:
https://youtu.be/8LusJS5-AGo?t=928
https://www.youtube.com/watch?v=YRBON9sIZ2Y
https://leetcode.com/discuss/interview-question/535706/maximum-quantity-of-items-dp-question/471080
"""