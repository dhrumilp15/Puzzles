import sys
from math import gcd

input = sys.stdin.readline

with open('fracs.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

num = int(input())
den = int(input())

big = gcd(num,den)
frac = num // den
if num % den == 0:
    print(num //den)
else:
    if num <= den:
        print(f"{num //big}/{den//big}")
    else:
        num //= big
        den //= big
        left = num - den*frac
        print(f"{frac} {left}/{den}")
