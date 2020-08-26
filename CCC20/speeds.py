import sys

input = sys.stdin.readline

# import os
# os.chdir(os.path.dirname(os.path.abspath(__file__)))
# with open('speeds.in', 'r') as f:
#     read = f.read().strip().split('\n')
# dataiter = iter(read)
# def input():
#     return next(dataiter)

ats = int(input().strip())

obs = []

for race in range(ats):
    obs.append(tuple(map(int, input().strip().split())))

obs.sort(key = lambda x: x[0])
diffs = [abs(ob[1] - obs[index][1]) / abs(ob[0] - obs[index][0])  for index, ob in enumerate(obs[1:])]
# print(diffs)
print(max(diffs))