# import sys

# input = sys.stdin.readline

with open('2in.txt', 'r') as f:
    data = f.read()

data = data.split('\n')
# print(data)
dataiter = iter(data)

def input():
    line = next(dataiter)
    return str(line)

N, M = map(int,input().strip().split(' '))

A, B = map(int,input().strip().split(' '))

powerlevels = []
for _ in range(6):
    powerlevels.append(list(map(int, input().strip().split(' '))))

print(powerlevels)