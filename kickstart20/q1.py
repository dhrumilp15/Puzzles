import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('q1.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

cases = int(input().strip())
for case in range(1, cases + 1):
    # print(input().strip().split())
    N, B = map(int, input().strip().split())
    buy = 0
    prices = list(map(int, input().strip().split()))
    prices.sort()
    total = 0
    for price in prices:
        total += price
        if B < total:
            total -= price
        else:
            buy += 1
    print("Case #{}: {}".format(case, buy))