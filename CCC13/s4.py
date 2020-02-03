import sys

def bfs(start, target):
    queue = [start]
    beenTo = [start]
    while queue:
        current = queue.pop()        
        for i in kids[current]:
            if i not in beenTo:
                queue.append(i)
                if i == target:
                    return True
                beenTo.append(i)
    return False

input = sys.stdin.readline
ppl, comps = map(int, input().split(" "))

kids = [[] for _ in range(ppl + 1)]
 
for _ in range(comps):
    tall, short = map(int, input().split(" "))
    kids[tall].append(short)

start, stop = map(int, input().split(" "))

if bfs(start, stop):
    print("yes")
elif bfs(stop, start):
    print("no")
else:
    print("unknown")