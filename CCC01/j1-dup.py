import sys
input = sys.stdin.readline

N = int(input())

for j in range(1, N + 1, 2):
    print('*'*j, end = "")
    print(' '*(2*(N - j)), end = "")
    print('*'*j)
for i in range(N-2, 0, -2):
    print('*'*i, end = "")
    print(' '*(2*(N - i)), end = "")
    print('*'*i)
