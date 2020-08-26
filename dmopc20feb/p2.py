import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('p2.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

N, H = map(int, input().strip().split())

c, e = H, H
cmoves, emoves = [], []
# movelist = [None] * 2 * N

for _ in range(N):
    seq = input().strip().split()
    cmoves.append((seq[0].upper(), int(seq[1])))

for _ in range(N):
    seq = input().strip().split()
    emoves.append((seq[0].upper(), int(seq[1])))

# print(cmoves, emoves)
for move in range(N):
    # print(f"enemy: {e}, charlie: {c}")
    if e <= 0:
        print('VICTORY')
        break
    if c <= 0:
        print('DEFEAT')
        break
    if cmoves[move][0] == 'A':
        if move == 0:
            e -= cmoves[move][1]
            if e <= 0:
                print('VICTORY')
                break
        else:
            if emoves[move - 1][0] != 'D':
                e -= cmoves[move][1]
                if e <= 0:
                    print('VICTORY')
                    break
        

        if emoves[move][0] == 'A':
            c -= emoves[move][1]
            if c <= 0:
                print('DEFEAT')
                break
    else:
        if move != 0:
            if emoves[move - 1][0] == 'D':
                e -= emoves[move - 1][1]
                if e <= 0:
                    print('VICTORY')
                    break
        if emoves[move][0] == 'D':
            c -= cmoves[move][1]
            if c <= 0:
                print('DEFEAT')
                break
else:
    tieflag = True
    if emoves[-1][0] == 'D':
        e -= emoves[-1][1]
        if e <= 0:
            print('VICTORY')
            tieflag = False
    if tieflag:
        print('TIE')