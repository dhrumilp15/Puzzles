import sys
input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('p3.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

cases = int(input().strip())
moves = {'N' : [0,-1], 'S' : [0,1], 'E':[1,0], 'W':[-1,0]}

big = int(1e9) # Thank you @Dessertion for showing me that 1e9 is a float

for case in range(1, cases + 1):
    dirs = input().strip()
    multiplier = [1]
    mul = 1
    position = [1,1]
    for letter in dirs:
        if letter == '(':
            continue
        elif letter == ')':
            if len(multiplier) > 1:
                mul //= multiplier.pop()
            continue
        elif letter.isdigit():
            multiplier.append(int(letter))
            mul *= int(letter)
            continue
        else:
            x_change = moves[letter][0] * mul
            y_change = moves[letter][1] * mul
            position[0] = (position[0] + x_change) % big
            position[1] = (position[1] + y_change) % big
            if position[0] == 0:
                position[0] = big
            if position[1] == 0:
                position[1] = big
    print("Case #{}: {} {}".format(case, int(position[0]), int(position[1])))