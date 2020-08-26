import sys

input = sys.stdin.readline

cases = int(input())

for case in range(1, cases + 1):
    workers, broken, lines = map(int, input().strip().split())
