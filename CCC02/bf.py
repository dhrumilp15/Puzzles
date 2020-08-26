import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('bf.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

dirs = ["N", "E", "S", "W"]

rows = int(input())
cols = int(input())

yard = [['.' for col in range(cols)] for row in range(rows)]

for row in range(rows):
    lawnrow = input()
    for col, char in enumerate(lawnrow):
        if char == 'X':
            yard[row][col] = 'X'
# print(yard)

N = int(input())

insts = []
for inst in range(N):
    insts.append(input().strip())

# print(insts)

finishes = set()
for row in range(rows):
    for col in range(cols):
        # print(f"Start position: {row}, {col}")
        # You can start from this position if it isn't an X
        if yard[row][col] != 'X':
            # print(f"Considered: {row} {col}")            
            # Loop through all possible directions
            for startdir in range(4):
                pos = [row,col]
                # print(f"{pos} Starting in the direction of {dirs[startdir]}")
                facing = startdir
                # Loop through the instructions
                # print()
                for instindex, inst in enumerate(insts):
                    # print(f"travelled to point {pos}")
                    if inst == 'F':
                        di = dirs[facing]
                        # print(f"Facing {di}")
                        if di == 'N':
                            if pos[0] == 0:
                                # print(f"{row}, {col} facing {dirs[startdir]} hit the edge")
                                break
                            elif yard[pos[0]-1][pos[1]] == 'X':
                                # print(f"{row}, {col} facing {dirs[startdir]} hits X")
                                break
                            pos[0] -= 1
                        
                        elif di == 'W':
                            if pos[1] == 0:
                                # print(f"{row}, {col} facing {dirs[startdir]} hit the edge")
                                break
                            elif yard[pos[0]][pos[1] - 1] == 'X':
                                # print(f"{row}, {col} facing {dirs[startdir]} hits X")
                                break
                            pos[1] -= 1
                        
                        elif di == 'S':
                            if pos[0] == rows - 1:
                                # print(f"{row}, {col} facing {dirs[startdir]} hit the edge")
                                break
                            elif yard[pos[0]+1][pos[1]] == 'X':
                                # print(f"{row}, {col} facing {dirs[startdir]} hits X")
                                break
                            pos[0] += 1
                        
                        elif di == 'E':
                            if pos[1] == cols - 1:
                                # print(f"{row}, {col} facing {dirs[startdir]} hit the edge")
                                break
                            elif yard[pos[0]][pos[1] + 1] == 'X':
                                # print(f"{row}, {col} facing {dirs[startdir]} hits X")
                                break
                            pos[1] += 1
                        # print(f"Travelled to {pos}")
                    elif inst == 'R':
                        facing = (facing + 1) % 4
                    elif inst == 'L':
                        facing = (facing - 1) % 4
                    # print()
                else:
                    # print(f"added {pos} to finishes")
                    finishes.add((pos[0], pos[1]))
                # print()
# print(finishes)
for finish in finishes:
    yard[finish[0]][finish[1]] = '*'
for row in yard:
    print(''.join(row))