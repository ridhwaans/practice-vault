# This question was asked by Twitch, 2021
#
# 1) Create a type of a linked list
# 2) Given a sentence, return a version of the linked list. Write test cases to verify that it works
# 3) Write a method to find the nth node from the end of the linked list
# 4) Write a method to find the reverse of the linked list

# Assumptions:
# - linked list is single linked list
# - linked list should not be empty or all whitespace
# - sentences can contain letters, numbers, or special characters
# - space is the delimiter for the sentence

class Node
  attr_accessor :node_value, :next_node
  def initialize(node_value, next_node=nil)
      @node_value = node_value
      @next_node = next_node
  end
end

def insert(node, word)
  if node.nil?
    Node.new(word)
  end
  temp = nil
  while !node.nil? do
    temp = node
    node = node.next_node
  end
  temp.next_node = Node.new(word)
  temp.next_node
end

def reverseLList(root, prev_node=nil)
  return prev_node unless root
  next_node = root.next_node
  root.next_node = prev_node
  # recursive
  reverseLList(next_node, root)
end

def printNthFromLast(root, n)
  temp = root
  length = 0
  while !temp.nil?
    temp = temp.next_node
    length += 1
  end
  if n > length
    p "location is greater than length of linked list"
  end
  temp = root
  (length - n).times do
    temp = temp.next_node
  end
  p temp.node_value
end

def printAll(root)
  while !root.nil? do
    print root.node_value + " "
    root = root.next_node
  end
  puts # new line
end

def verifyLList(sentence, root_node)
  correct = true
  sentence.split(" ").each do |word|
    # if linked list has reached the end before the sentence ends or node value is incorrect, return false
    if root_node.nil? || word != root_node.node_value
      correct = false
      return correct
    end
    root_node = root_node.next_node
    
  end
  # if linked list has not reached the end after the sentence ends, return false
  if !root_node.nil?
    correct = false
  end
  # true if all words have been correctly mapped to linked list
  correct
end

def stringToLList(sentence)
  if sentence.nil?
    return "error. sentence is nil"
  elsif sentence.strip.empty?
    return "error. sentence is empty or all whitespace"
  end
  
  # save head node to return it afterwards
  root = Node.new(nil)
  current_node = root
  sentence.split(" ").each_with_index do |word, i|
    current_node = insert(root, word)
    root = current_node if root.node_value.nil?
  end
  root
end

# testing
p stringToLList(nil)
p stringToLList("")
p stringToLList("   ")

testString = "fluffy is a dragon that breathes fire"
root = stringToLList(testString)
p root.node_value

p verifyLList("fluffy is a dragon that breathes", root)
p verifyLList("fluffy is a dragon that breathes water", root)
p verifyLList("fluffy is a dragon that breathes fire and water", root)
p verifyLList(testString, root)

printNthFromLast(root, 2)

printAll(root)
reversedRoot = reverseLList(root)
printAll(reversedRoot)

# "error. sentence is nil"
# "error. sentence is empty or all whitespace"
# "error. sentence is empty or all whitespace"
# "fluffy"
# false
# false
# false
# true
# "breathes"
# fluffy is a dragon that breathes fire 
# fire breathes that dragon a is fluffy 

# time complexity is O(n)
# space complexity is O(n)