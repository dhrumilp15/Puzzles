import sys
from math import inf

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('p4.txt', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

group_size = int(input())
ppl = int(input())

names = []
times = []

for _ in range(ppl):
    names.append(input())
    times.append(int(input()))

dplist = [inf] * (ppl + 1)
dplist[0] = 0
groups = [-1] * (ppl+1)

for person in range(ppl + 1):
    best = 0
    for other in range(1, group_size + 1):
        if person + other - 1 < ppl:
            best = max(best, times[person + other - 1])
            if dplist[person] + best < dplist[person + other]:
                dplist[person + other] = dplist[person] + best
                groups[person + other] = other

people = [0] * (ppl + 1)

last = ppl
num_groups = 0
while groups[last] != -1:
    people[num_groups] = groups[last]
    last -= groups[last]
    num_groups += 1
cutoff = 0
print(f"Total Time: {dplist[ppl]}")
for size in range(num_groups-1,-1,-1):
    print(' '.join(names[cutoff:cutoff + people[size]]).strip())
    cutoff += people[size]