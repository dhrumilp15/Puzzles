import sys
from math import inf
dist = int(sys.stdin.readline())

dpable = [inf]*(dist+1)
clubs = []
for _ in range(int(sys.stdin.readline())):
    ind = int(sys.stdin.readline())
    clubs.append(ind)
    dpable[ind] = 1

def ppdp(index):
    if index < 0:
        return inf
    if dpable[index] != inf:
        return dpable[index]
    strokes = inf
    for club in clubs:
        strokes = min(strokes, ppdp(index - club) + 1)
    dpable[index] = strokes
    return dpable[index]

answer = ppdp(dist)
print("Roberta wins in {} strokes.".format(answer)) if answer != inf else print("Roberta acknowledges defeat.")
