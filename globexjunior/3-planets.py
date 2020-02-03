# import sys

# input = sys.stdin.readline

with open('3in.txt', 'r') as f:
    data = f.read()

data = data.split('\n')
# print(data)
dataiter = iter(data)

def input():
    line = next(dataiter)
    return str(line)

N, k = map(int, input().strip().split(' '))

planetdic = []

for _ in range(N):
    planet, size = input().strip().split(' ')
    size = int(size)
    planetdic.append((planet,size))

planetdic = sorted(planetdic)
for i in range(1, N):
    



print(' '.join(sorted(planets)))
