import sys
from collections import defaultdict

input = sys.stdin.readline
with open('sbomb.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

graph = defaultdict(list)
nodes = set()
adjlist = []
adj = input().strip()
while adj != '**':
    graph[adj[0]].append(adj[1])
    graph[adj[1]].append(adj[0])
    nodes.add(adj[0])
    nodes.add(adj[1])
    adjlist.append(adj)
    adj = input().strip()

# Bruteforce algo to exclude an edge and see if you can get from A to B
def bfs(excluded):
    visited = dict(zip(nodes, [False] * len(graph)))
    visited['A'] = True
    queue = []
    queue.append('A')
    while queue:
        node = queue.pop(0)
        # print(f"From parent: {node}")
        for child in graph[node]:
            if not (node in excluded and child in excluded):
                if not visited[child]:
                    if child == 'B':
                        return True
                    visited[child] = True
                    queue.append(child)
    return False

discon = []
for path in adjlist:
    if bfs(path) == False:
        discon.append(path)

if discon:
    for path in discon:
        print(path)
print(f"There are {len(discon)} disconnecting roads.")