import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('q1.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

ciphertext = list(input())
for letter in range(len(ciphertext)):
    if ciphertext[letter].islower():
        small_letter = ciphertext[letter]
        ciphertext[letter] = chr(25 - ord(small_letter) + 2 * ord('a'))
print(''.join(ciphertext))