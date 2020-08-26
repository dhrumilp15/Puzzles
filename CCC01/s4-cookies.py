import sys
from math import sqrt

input = sys.stdin.readline

with open('cookies.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

def calc_dist(A, B):
    return (B[0] - A[0]) ** 2 + (B[1] - A[1]) ** 2

N = int(input().strip())
points = [None] * N
for point in range(N):
    points[point] = list(map(float,input().strip().split()))

# print(points)
# Sort by distance from the origin
sortedpoints = sorted(points, key = lambda x: x[0]**2 + x[1]**2)

# start with midpoint
midpoint = [(sortedpoints[0][0] + sortedpoints[-1][0]) / 2,(sortedpoints[0][1] + sortedpoints[-1][1]) / 2]
# print(midpoint)
midpointdist = sortedpoints[0][0]
min_dist = calc_dist(sortedpoints[0], midpoint)

def checkdists(test_dist, test_center):
    flag = True
    failing = []
    for point in points:
        pointdist = calc_dist(test_center, point)
        if pointdist > test_dist:
            flag = False
            failing.append(point)
    return flag, failing

midflag, failing = checkdists(min_dist, midpoint)
# print(sortedpoints)

if midflag:
    print(f"{2*sqrt(min_dist):.2f}")
else:
    # print(failing)
    combos = []
    if len(failing) == 1:
        combos.append([sortedpoints[0], sortedpoints[-1], failing[0]])
    elif len(failing) == 2:
        combos.append([failing[0], failing[1], sortedpoints[0]])
        combos.append([failing[0], failing[1], sortedpoints[-1]])
    else:
        failinglen = len(failing)
        for i in range(failinglen):
            for j in range(i + 1, failinglen):
                for k in range(j + 1, failinglen):
                    combos.append([failing[i], failing[j], failing[k]])
    
    diams = []
    for combo in combos:
        # print(f"combo: {combo}")
        D = 2.0 * (combo[0][0] * (combo[1][1] - combo[2][1]) + combo[1][0] * (combo[2][1] - combo[0][1]) + combo[2][0] * (combo[0][1] - combo[1][1]))
        xcenter = (1 / float(D)) * ((combo[0][0] * combo[0][0] + combo[0][1] * combo[0][1]) * (combo[1][1] - combo[2][1]) + (combo[1][0] * combo[1][0] + combo[1][1] * combo[1][1]) * (combo[2][1] - combo[0][1]) + (combo[2][0] * combo[2][0] + combo[2][1] * combo[2][1]) * (combo[0][1] - combo[1][1]) )
        ycenter = (1 / float(D)) * ((combo[0][0] * combo[0][0] + combo[0][1] * combo[0][1]) * (combo[2][0] - combo[1][0]) + (combo[1][0] * combo[1][0] + combo[1][1] * combo[1][1]) * (combo[0][0] - combo[2][0]) + (combo[2][0] * combo[2][0] + combo[2][1] * combo[2][1]) * (combo[1][0] - combo[0][0]) )
        # print(xcenter, ycenter)
        diam = 2*sqrt(calc_dist([xcenter,ycenter], combo[0]))
        # print(diam)
        diams.append(diam)
    print(f"{min(diams):.2f}")
    
    