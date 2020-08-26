import sys
input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('s4golf.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

totalsize = int(input().strip())
# print(totalsize)
dplist = [5281] * (totalsize + 1)
clubs = [int(input()) for _ in range(int(input()))]
dplist[0] = 0

for i in range(totalsize + 1):
    for club in clubs:
        if i + club <= totalsize:
            if dplist[i] + 1 < dplist[i + club]:
                dplist[i + club] = dplist[i] + 1

if dplist[totalsize] < 5281:
    print(f"Roberta wins in {dplist[totalsize]} strokes.")
else:
    print("Roberta acknowledges defeat.")
