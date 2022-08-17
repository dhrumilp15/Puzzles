import sys
input = sys.stdin.readline

k = int(input())

h = list(map(int, input().strip().split()))
w = list(map(int, input().strip().split()))

total = 0
for i in range(k):
    total += (w[i] * (h[i] + h[i + 1]) / 2.0)

if int(total) == total:
    print(int(total))
else:
    print(round(total, 1))
