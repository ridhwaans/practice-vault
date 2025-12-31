"""
Daily Coding Problem: Problem #1

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
"""

def twoSum(arr, k)
    differences = {}
    arr.each_with_index do |number, idx|
        if differences.has_key?(k - number)
          return true
        else
          differences[number] = idx
        end
      end
      false
end

puts "given %s and k of %s, return %s" % [[2,1,1], 4, twoSum([2,1,1], 4)]
puts "given %s and k of %s, return %s" % [[10,15,3,7], 17, twoSum([10,15,3,7], 17)]
puts "given %s and k of %s, return %s" % [[10,-15,3,7], -5, twoSum([10,-15,3,7], -5)]
puts "given %s and k of %s, return %s" % [[1,2,3], 10, twoSum([1,2,3], 10)]
puts "given %s and k of %s, return %s" % [[10,15,3,7], 10, twoSum([10,15,3,7], 10)]

