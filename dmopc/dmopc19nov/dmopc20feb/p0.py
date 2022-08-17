import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('p0.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

N, cutoff = map(int, input().strip().split())

for _ in range(N):
    person, score = input().strip().split()
    score = int(score)
    message = ""
    if cutoff >= score:
        message = "not "
    print(f"{person} will {message}advance")