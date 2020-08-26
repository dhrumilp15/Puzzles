import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('Mural.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

cases = int(input().strip())

for case in range(cases):
    length = int(input().strip())
    wall = list(map(int, list(input().strip())))
    usedwall = wall[:]
    unseen = length
    points = 0
    most = max(usedwall)
    while usedwall:
        points += most
        
        if most != usedwall[0] or most != usedwall[-1]:
            usedwall.remove(max(usedwall[0], usedwall[-1]))
        elif most != usedwall[0]:
            usedwall.pop(0)
        elif most != usedwall[-1]:
            usedwall.pop(-1)
        top = max(usedwall[usedwall.index(most) - 1], usedwall[usedwall.index(most) + 1])
        usedwall.remove(most)
        most = top
        
    print(points)

