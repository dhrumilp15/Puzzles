import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('p2.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

cases = int(input())

for case in range(1, cases + 1):
    X, D = map(int, input().strip().split())
    buses = list(map(int, input().strip().split()))
    current = D
    for bus in buses[::-1]:
        current = current // bus * bus
    print("Case #{}: {}".format(case, current))
