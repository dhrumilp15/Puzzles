import sys
from math import inf

input = sys.stdin.readline

with open('scb.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

prices = []
combos = 0

for price in range(4):
    prices.append(int(input().strip()))
# print(prices)
target = int(input().strip())

minticket = inf

ticket = target
buy = [0] * 4
currmin = 0
for pink in range(target // prices[0] + 1):
    pinknum = pink * prices[0]
    for green in range(target // prices[1] + 1):
        greennum = green * prices[1]
        for red in range(target // prices[2] + 1):
            rednum = red * prices[2]
            for orange in range(target // prices[3] + 1):
                orangenum = orange * prices[3]
                if pinknum + greennum + rednum + orangenum == target:
                    minticket = min(minticket, pink + green + red + orange)
                    combos += 1
                    print(f"# of PINK is {pink} # of GREEN is {green} # of RED is {red} # of ORANGE is {orange}")

print(f"Total combinations is {combos}.")
print(f"Minimum number of tickets to print is {minticket}.")