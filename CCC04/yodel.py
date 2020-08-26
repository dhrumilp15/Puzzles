import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('yodel.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

ppl, rounds = map(int, input().strip().split())

scores = [0] * ppl

for round in range(rounds):
    for index, score in enumerate(map(int, input().strip().split())):
        scores[index] += score
    
scores.sort(reverse = True)
print(scores)
