'''
This question was asked by CircleCI, Karat (2021)

There is an m x n rectangular 2d array called board which has rows and columns containing '0' or '+' only.
Rows and columns start at index 0
The '0' value means it is a passable path whereas the '+' value is a wall that cannot be crossed.
You are a snake that can move in four directions- up, down, left, right. Entering and exiting the board must only happen at a '0' value. You can enter the board from any four sides/borders
After entering the board, there can be multiple exits. Find the nearest exit

EXAMPLE

+ 0 0 + + + 
+ 0 0 0 + +
+ + + 0 + +
+ + + 0 + +
0 + 0 0 0 0
0 0 0 + + +

board = [
['+','0','0','+', '+', '+'],
['+','0','0','0', '+', '+'],
['+','+','+','0', '+', '+'],
['+','+','+','0', '+', '+'],
['0','+','0','0', '0', '0'],
['0','0','0','+', '+', '+']
]

find_exit(board, (4, 5))

OUTPUT
(5,2)

EXPLANATION
You are given the board array and a set of coordinates. 4 is the rowId, 5 is the columnId for entry
There are multiple exits. The goal is to find the nearest exit
Exit is at row 5 column 2
Answer is (5,2)

Assumptions:
- At least one exit
- Input can be one dimensional
- Elements are strings
- Can mutate the input

Algorithm:
[
    ['+','0','0','+', '+', '0'],
    ['+','0','0','0', '+', '+'],
    ['+','+','+','0', '+', '+'],
    ['+','+','+','0', '+', '+'],
    ['0','+','0','0', '0', '0'],
    ['0','0','0','+', '+', '+']
]

minimumPathLength = (integer)

Recursive function DFS():
    if current cell is at border:
        record this as a solution
    Mark cell as visited
    Explore surrounding cells for possible paths ('0')
    for each path:
        call DFS()
'''

def find_exit(board, start):
    m = len(board)
    n = len(board[0])
    
    minimumPathLength = float('inf')
    output = None
    
    def dfs(cell, pathLength):
        nonlocal output
        nonlocal minimumPathLength
        
        if pathLength >= minimumPathLength:
            return
        
        r, c = cell
        if cell != start and (r == m-1 or r == 0 or c == n-1 or c == 0):
            if pathLength < minimumPathLength:
                minimumPathLength = pathLength
                output = cell
                return
            
        board[r][c] = '+'
            
        dirs = [[0,1],[1,0],[-1,0],[0,-1]]
        
        for dr, dc in dirs:
            r1, c1 = r+dr, c+dc
            if r1 >= 0 and r1 < m and c1 >= 0 and c1 < n and board[r1][c1] == '0':
                dfs([r1,c1], pathLength+1)
    
    dfs(start, 0)
    
    if not output:
        return 'No exit found'
    
    return output

board = [
    ['0'],
    ['0'],
    ['0'],
    ['+']
]

print(find_exit(board, [0,0]))

board = [
    ['0','0','0','+']
]

print(find_exit(board, [0,0]))

board = [
    ['0','+']
]

print(find_exit(board, [0,0]))

board = [
    ['+','0','0','+', '+', '0'],
    ['+','0','0','0', '+', '+'],
    ['+','+','+','0', '+', '+'],
    ['+','+','+','0', '+', '+'],
    ['0','+','0','0', '0', '0'],
    ['0','0','0','+', '+', '+']
]

print(find_exit(board, [4,5]))

# Complexity:
# time: O(M*N)
# space: O(1) if modifying input. O(N*M) otherwise