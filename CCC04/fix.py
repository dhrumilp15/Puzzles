import sys
from itertools import combinations

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('fix.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

bags = int(input())

for bag in range(bags):
    fixflag = True
    words = []
    for word in range(3):
        words.append(input().strip())
    # print(words)
    
    for index, word in enumerate(words):
        for ind, oword in enumerate(words): # Suppose a repeated word
            if index != ind and (oword.startswith(word) or oword.endswith(word)):
                fixflag = False
            # length = 0
            # while length < min(len(word), len(oword)):
            #     print(word)
            #     if oword.startswith(word[:length]) or oword.endswith(word[:length]):
            #         fixflag = False
            #     length += 1
    
    if fixflag:
        print("Yes")
    else:
        print("No")