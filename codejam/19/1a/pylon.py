import sys
sys.setrecursionlimit(200000)

input = sys.stdin.readline

# import os
# os.chdir(os.path.dirname(os.path.abspath(__file__)))
# with open('pylon.in', 'r') as f:
#     read = f.read().strip().split('\n')
# dataiter = iter(read)
# def input():
#     return next(dataiter)

cases = int(input())

def jumpable(start, dest):
    if start:
        return start[0] != dest[0] and start[1] != dest[1] and start[0] - start[1] != dest[0] - dest[1] and start[0] + start[1] != dest[0] + dest[1]
    else:
        return True

def search(rows, cols):
    total = rows * cols
    def dfs(start, visited, pending):
        if not pending:
            return visited
        for loc in [point for point in pending if jumpable(start, point)]:
            pending.remove(loc)
            sol = dfs(loc, visited + [loc], pending)
            pending.add(loc)
            if sol and len(sol) == total:
                return sol
    
    return dfs(None, [], {(row,col) for col in range(1, cols + 1) for row in range(1, rows + 1)})

def solve(rows, cols):
    for a, b in [(a,b) for a in range(1, a + 1) for b in range(1, b + 1)]:
        sol = search(rows, cols)
        if sol:
            return sol

for case in range(1, cases + 1):
    rows, cols = map(int, input().strip().split())
    
    sol = search(rows, cols)
    if sol:
        print("Case #{}: POSSIBLE".format(case))
        for node in sol:
            print("{} {}".format(node[0], node[1]))
    else:
        print("Case #{}: IMPOSSIBLE".format(case))