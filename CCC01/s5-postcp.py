import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('s5-postcp.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

# M = 1,2,4,5,8,10,20,40
# N = 40,20,10,8, 4, 2, 1

# at most you'll need M calls to solve this

M = int(input().strip())
N = int(input().strip())

A = [input().strip() for _ in range(N)]
B = [input().strip() for _ in range(N)]

seq = [0] * 40

flag = False
def find(Astr, Bstr, pos):
    global N, M, flag
    
    if flag:
        return
    
    if Astr and Astr == Bstr:
        flag = True
        print(pos)
        for letter in range(pos):
            print(seq[letter] + 1)
        return
    
    if pos == M:
        return
    
    minlen = min(len(Astr), len(Bstr))
    
    if Astr[:minlen] != Bstr[:minlen]:
        return
    
    for index in range(len(A)):
        seq[pos] = index
        find(Astr + A[index], Bstr + B[index], pos + 1)
        # while index < N and not fin:
        #     K = pos
        #     seq[K] = index
        #     fin = find(Astr, A[index], Bstr, B[index], pos + 1)
        #     index += 1
        # return fin

find("", "", 0)
if not flag:
    print("No solution.")