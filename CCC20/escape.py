import sys
from math import sqrt
input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('escape.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

rows = int(input())
cols = int(input())

board = [list(map(int, input().strip().split())) for row in range(rows)]
start = (0,0)

def solve():
    target = (rows -1 , cols - 1)
    visited = set()
    value_visited = set()
    stack = [start]

    while stack:
        current = stack.pop()
        
        if current == target or (current[1], current[0]) == target:
            return 'yes'
        else:
            current_value = board[current[0]][current[1]]
            if current not in visited and current_value not in value_visited: # unique position + unique value
                for factor, other in ((i, current_value//i) for i in range(1, int(sqrt(current_value)) + 1) if current_value % i == 0): # only computing factors for new numbers
                    if (factor - 1, other - 1) == target or (other - 1, factor - 1) == target:
                        return 'yes'
                    if factor - 1 < rows and other - 1 < cols and (factor-1, other-1) not in visited and board[factor-1][other-1] not in value_visited:
                        stack.append((factor-1, other-1))
                    if factor - 1 < cols and other - 1 < rows and (other-1,factor-1) not in visited and factor != other and board[other-1][factor-1] not in value_visited:
                        stack.append((other-1,factor-1))
                
                visited.add(current)
                value_visited.add(current_value)
    return 'no'

print(solve())