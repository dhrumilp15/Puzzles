import sys
input = sys.stdin.readline

x = int(input())
m = int(input())

for i in range(0,m+1):
    if x*i % m == 1:
        print(i)
        break
    if i == m:
        print('No such integer exists.')