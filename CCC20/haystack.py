import sys
from itertools import product, permutations, combinations

input = sys.stdin.readline

# import os
# os.chdir(os.path.dirname(os.path.abspath(__file__)))
# with open('haystack.in', 'r') as f:
#     read = f.read().strip().split('\n')
# dataiter = iter(read)
# def input():
#     return next(dataiter)

needle = input().strip()

haystack = input().strip()

given = set()
count = 0

def perms():
    pool = tuple(needle)
    n = len(pool)
    indices = list(range(n))
    cycles = list(range(n ,0, -1))
    given.add(needle)
    while n:
        for i in reversed(range(n)):
            cycles[i] -= 1
            if cycles[i] == 0:
                indices[i:] = indices[i+1:] + indices[i:i+1]
                cycles[i] = n - i
            else:
                j = cycles[i]
                indices[i], indices[-j] = indices[-j], indices[i]
                given.add(''.join(pool[i] for i in indices[:n]))
                break
        else:
            return

perms()
for perm in given:
    if perm in haystack:
        count += 1

print(count)
