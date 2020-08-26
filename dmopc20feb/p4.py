import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('p4.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

N, Q = map(int, input().strip().split())

money = list(map(int, input().strip().split()))
people = list(map(int, input().strip().split()))
friends = list(zip(people, money))
friends.sort(key = lambda x: x[0])

att = [None] * N
path = []

def find(target, rank = friends[-1][0], currsum = 0):
    for index, friend in enumerate(friends[::-1]):
        for victim in friends[:index][::-1]:
            if victim[0] >= friend[0]:
                continue
            

for query in range(Q):
    veshy, lunch = map(int, input().strip().split())
    if veshy >= lunch:
        print(-1)
        continue
    target = lunch - veshy
    find(target, rank=max(people))
    print(att)

    

