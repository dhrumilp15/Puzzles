import sys

input = sys.stdin.readline

N = int(input())

ppl = list(map(int, input().strip().split()))

total = sum(ppl)

fair = total // N

mis = 0
for person in ppl:
    if person != fair:
        mis += 1

print(mis)