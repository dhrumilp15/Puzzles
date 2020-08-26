import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('poetry.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)
vowels = ['a', 'e', 'i', 'o', 'u']

verses = int(input().strip())
# print(verses)
for verse in range(verses):
    lines = []
    for i in range(4):
        line = input().strip().lower().split()
        lines.append(line)
        # print(line)
    # print(lines)
    ls = []
    for line in lines:
        last = line[-1]
        wordlength = len(last)
        for index, letter in enumerate(last[::-1]):
            if letter in vowels:
                ls.append(last[wordlength - index - 1:])
                break
        else:
            ls.append(last)
    
    if ls[0] == ls[1] and ls[1] == ls[2] and ls[2] == ls[3]:
        print("perfect")
    elif ls[0] == ls[1] and ls[2] == ls[3]:
        print("even")
    elif ls[0] == ls[2] and ls[1] == ls[3]:
        print("cross")
    elif ls[0] == ls[3] and ls[1] == ls[2]:
        print("shell")
    else:
        print("free")


