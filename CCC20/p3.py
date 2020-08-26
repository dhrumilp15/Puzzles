import sys
from functools import reduce

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('p3.txt', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

pattern = input().strip()
string = input().strip()
patL = len(pattern)
stringL = len(string)

primes = {'a': 2,'b': 3,'c': 5,'d': 7,'e': 11,'f': 13,'g': 17,'h': 19,'i': 23,'j': 29,'k': 31,'l': 37,'m': 41,'n': 43,'o': 47,'p': 53,'q': 59,'r': 61,'s': 67,'t': 71,'u': 73,'v': 79,'w': 83,'x': 89,'y': 97,'z': 101}

pat_prod = reduce(lambda x,y: x*y, (primes[letter] for letter in pattern))
patterns = set()
count = 0

first = reduce(lambda x,y: x*y, (primes[letter] for letter in string[:patL]))
if first == pat_prod:
    count += 1
    patterns.add(string[:patL])

for index in range(stringL - patL):
    first = (first // primes[string[index]]) * primes[string[index + patL]]
    if first == pat_prod:
        if string[index+1:index+patL+1] not in patterns:
            count += 1
            patterns.add(string[index+1: index + patL+1])
print(count)
