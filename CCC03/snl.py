import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('snl.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

snakes = {99: 77, 90:48, 54: 19}
ladders = {40: 64, 9:34, 67:86}

curr = 1
roll = int(input())
while True:
    if roll == 0:
        print("You Quit!")
        break
    if curr + roll <= 100:
        curr += roll
        # print(f"Got to square {curr}")
        # print(curr in snakes)
        # print(curr in ladders)
        
        if curr in snakes.keys():
            curr = snakes[curr]
            # print(f"Which slides to {curr}")
        elif curr in ladders.keys():
            curr = ladders[curr]
            # print(f"Which leads to {curr}")

    if curr <= 100:
        print(f"You are now on square {curr}")
    if curr == 100:
        print("You Win!")
        break
    roll = int(input())
