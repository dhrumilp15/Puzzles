import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('btree.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

w = int(input())

values = [None] * (w // 2)
values[0] = 1

for value in range(2, w // 2 + 1):
    for k in range(2, value + 1):
        total = 0
        values[value - 1] = values[w // value]
    
print(values)