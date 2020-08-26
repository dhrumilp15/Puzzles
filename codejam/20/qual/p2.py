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
    depth = 0
    final = ""
    digits = list(map(int, input().strip()))
    for digit in digits:
        change = digit - depth
        print(change)
        if change > 0:
            final += '('  * change
        else:
            final += ')' * abs(change)
        final += str(digit)
        depth += change
    final += ")" * depth
    print("Case #{}: {}".format(case, final))

