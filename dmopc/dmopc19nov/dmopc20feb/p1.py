import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('p1.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

N, M = map(int, input().strip().split())

items = set()

for _ in range(N):
    items.add(input().strip())

tasks = 0

for _ in range(M):
    flag = True
    reqs = int(input().strip())
    for req in range(reqs):
        if input().strip() not in items:
            flag = False
    if flag:
        tasks += 1
print(tasks)