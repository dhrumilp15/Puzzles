import sys

input=sys.stdin.readline

# with open('s5.in', "r") as f:
#     read = f.read().strip().split('\n')
# dataiter = iter(read)

# def input():
#     return next(dataiter)

def finddist(startx, targetx, targety):
    return (startx - targetx)**2 + targety**2

sheepnum = int(input().strip())

spoints = [[] for i in range(sheepnum)]

for i in range(2*sheepnum):
    spoints[i//2].append(float(input().strip()))

eat = [False] * sheepnum
# Only consider sheep that can be eaten
for sheep in spoints:
    # print(f"From: {sheep}")
    left = 0.0
    right = 1000.0
    for testsheep in spoints:
        # print(f"\tconsidering: {testsheep}")
        if testsheep != sheep and not eat[spoints.index(sheep)] and not eat[spoints.index(testsheep)]:
            if testsheep[1] == sheep[1]: # same y-value
                poi = (testsheep[0] + sheep[0]) / 2
            else:
                midpoint = [(testsheep[0] + sheep[0]) / 2, (testsheep[1] + sheep[1]) / 2]
                slope =  float(sheep[0] - testsheep[0]) / float(testsheep[1] - sheep[1]) # -1/m for perp slope
                # print(f"\t\tslope: {slope}")
                
                if slope == 0.0: # points are directly atop one another
                    if testsheep[1] > sheep[1]:
                        eat[spoints.index(testsheep)] = True
                    else:
                        eat[spoints.index(sheep)] = True
                else:
                    poi = -1.0 * (midpoint[1] / slope) + midpoint[0]
                    if testsheep[0] < sheep[0]:
                        left = max(poi, left)
                    else:
                        right = min(poi, right)
            # print(left, right)
    if left >= right:
        # print(f"Removed: {sheep}")
        eat[spoints.index(sheep)] = True

# BF
# x = 0.0
# while not x > 1000.0:
#     dists = []
#     for sheep in spoints:
#         dists.append(finddist(x, sheep[0], sheep[1]))
    
#     mindist = min(dists)
#     for index, dist in enumerate(dists):
#         if dist == mindist:
#             minsheep = spoints[index]
#             if not minsheep in chowtime:
#                 chowtime.append(minsheep)
#     x += 0.05
for index, sheep in enumerate(eat):
    if sheep == False:
        toeat = spoints[index]
        print(f"The sheep at ({toeat[0]:.2f}, {toeat[1]:.2f}) might be eaten.")