import sys
import os

input = sys.stdin.readline
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('p3.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

W, H = map(float, input().strip().split())
A, B = map(float, input().strip().split())
start = list(map(float, input().strip().split()))
vector = list(map(float, input().strip().split()))

print(W,H)

center = (start[0] + A / 2, start[1] + B / 2)
print(f"Center: {center}")
startslope = vector[1] / vector[0]

# RH = H - 2*B
# RW = W - 2*A

dist = 0
start = center
slope = startslope

while True:
    yint = start[1] - slope * start[0]
    leftwall = B / 2 <= yint and yint <= H - B / 2
    rightwall = B/2 <= slope * (W -A /2) + yint and slope * (W -A /2) + yint <= H - B / 2
    bottom = A / 2 <= -yint / slope and -yint / slope <= W - A/2
    top = A/2 <= (H - B / 2 - yint) / slope and (H - B / 2 - yint) / slope <= W - A/2
    print(leftwall, rightwall, bottom, top)

    if leftwall:
        # print("Calculate left wall")
        if bottom or top:
            start = (A/2, 0) if bottom else (A/2, H - B/2)
        else:
            start = (A / 2, yint)
    elif rightwall:
        # print("Calculate right wall")
        if bottom or top:
            start = (W - A/2, 0) if bottom else (W - A / 2, H - B/2)
        else:
            start = (W - B/2, slope * (W - B / 2) + yint)
    elif top:
        # print("Calculate top")
        if leftwall or rightwall:
            start = (A/2, H - B/2) if leftwall else (W - A / 2, H - B/2)
        else:
            start = ((H - B / 2 - yint) / slope, H - B / 2)
    elif bottom:
        # print("Calculate bottom")
        if leftwall or rightwall:
            start = (A/2, 0) if leftwall else (W - A/2, 0)
        else:
            start = (-yint / slope, 0)
    slope = - 1.0 * slope
    print(slope, start)
    if start == center and slope == startslope:
        break
    
