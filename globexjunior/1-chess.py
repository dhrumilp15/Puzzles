import sys

input = sys.stdin.readline

letters = list(map(int, input().strip().split(' ')))

wp = letters[2]
lp = letters[3]

winnable = list(map(int, input().strip().split(' ')))
playerord = list(map(int, input().strip().split(' ')))

rating = letters[1]
for player in playerord:
    if winnable[player - 1] == 1:
        rating += wp
    else:
        rating -= lp

print(rating)
