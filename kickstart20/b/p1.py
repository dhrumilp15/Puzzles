import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('p1.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

cases = int(input())

for case in range(1, cases + 1):
    N = int(input())
    hills = list(map(int, input().strip().split()))
    peaks = 0
    for check in range(1, N-1):
        peaks += 1 if hills[check] > hills[check - 1] and hills[check] > hills[check + 1] else 0
    print("Case #{}: {}".format(case, peaks))