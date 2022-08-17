import math
import sys
sys.setrecursionlimit(100000000)


def find_dist(a, b):
    return math.sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2)

def simper(pts, n):
    min_dist = int(1e9)
    for i in range(n):
        for j in range(i + 1, n):
            min_dist = min(min_dist, find_dist(pts[i], pts[j]))
    return min_dist

def find_min_dist(strip, most_size, dist):
    min_dist = dist
    for i in range(most_size):
        for j in range(i + 1, most_size):
            min_dist = min(min_dist, find_dist(strip[i], strip[j]))
    return min_dist, [strip[i], strip[j]]


def recurse(p_x, p_y, n):
    if n <= 3:
        return simper(p_x, n)
    middle = n // 2
    
    midpoint = p_x[middle][0]

    left_x = p_x[:middle]
    right_x = p_x[middle:]

    left_y = []
    right_y = []

    print("==")
    print(f'middle: {p_y[middle]}')
    for i in p_y:
        if x[0] <= midpoint and left_idx < middle:
            left_y.append(p_y[i])
        else:
            right_y.append(p_y[i])
        
    (p1, q1, left_dist) = recurse(p_x, left_pt, middle) 
    (p2, q2, right_dist) = recurse(p_x[middle:], right_pt, n - middle)
    dist = left_dist
    mn = [p1, q1]
    if right_dist <= left_dist:
        dist = right_dist
        mn = [p2, q2]

    (p3, q3, mid_dist) = 
    strip = [None] * n
    most_size = 0
    for i in range(n):
        if abs((p_y[i][0] - p_x[middle][0]) < dist):
            strip[most_size] = p_y[i]
            most_size += 1
    
    return min(dist, find_min_dist(strip, most_size, dist))

def solve(points):
    p_x = sorted(points, key= lambda p: p[0])
    p_y = sorted(points, key= lambda p: p[1])
    print(f'p_x: {p_x}')
    print(f'p_y: {p_y}')
    print('solving for k...')
    k = recurse(p_x, p_y, len(p_x))
    print(k)
    return k


print(f'solve: {solve([[2, 3], [12, 30], [40, 50], [5, 1], [12, 10], [3, 4]])}')

