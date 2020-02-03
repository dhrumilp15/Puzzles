import sys
input=sys.stdin.readline

sheep = []

with open('s5in.txt', "r") as f:
    read = f.read()
read = read.split("\n")

pairs = int(read.pop(0))
read = list(map(float, read))
for line in range(pairs*2):
    sheep.append((read[line - 1], read[line]))
f.close()

def squaredist(x,y):
    return ((y[1] - x[1])**2 + (y[0] - x[0])**2)

sheep.sort(key = lambda point: point[1])
print("Sheep", str(sheep))

smallest = set()

def smallsheep(x):
    sheepdists = []
    for index, sheepo in enumerate(sheep):
        sheepdists.append((sheepo[0] - x)**2 + sheepo[1]**2)

for x in range(1000):
    smallest.add(smallsheep(x))
    for sheepo in smallest:
        print("The sheep at {} might be eaten.".format(sheepo))