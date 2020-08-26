import sys
from math import inf, cos, sin, pi

input = sys.stdin.readline

cases, min_rad, max_rad = map(int, input().strip().split())
points = {}

def pprint(coords):
    print("{} {}".format(coords[0], coords[1]))
    sys.stdout.flush()

def find_circle():
    res = None
    coords = [(x, y) for x in range(-int(1e9), int(1e9) + 1, min_rad) for y in range(-int(1e9), int(1e9) + 1, min_rad)]
    for item in coords:
        x, y = item
        guess = [x, y]
        pprint(guess)
        res = input().strip()
        if res == "HIT" or res == "CENTER":
            return res, guess

def bin_search(coord_min, coord_max, mode="x+"):
    # Runtime of 2*log(skip)
    # print(f"min: {coord_min}, max: {coord_max}")
    if coord_min[0] == coord_max[0] and coord_max[1] == coord_min[1]:
        return "HIT", coord_max
    
    mid = ((coord_max[0] + coord_min[0]) // 2, (coord_max[1] + coord_min[1]) // 2)
    
    if mid in points:
        res = points[mid]
    else:
        pprint(mid)
        res = input().strip()
        points[mid] = res
    
    if res == "CENTER":
        return res, mid
    # For a miss
    elif res == "MISS":
        if mode == "x+":
            test_point = (mid[0] - 1, mid[1])
        elif mode == "x-":
            test_point = (mid[0] + 1, mid[1])
        elif mode == "y+":
            test_point = (mid[0], mid[1] - 1)
        else: # y-
            test_point = (mid[0], mid[1] + 1)
        if test_point in points:
            res = points[test_point]
        else:
            pprint(test_point)
            res = input().strip()
            points[test_point] = res
        if res == "HIT" or res == "CENTER": # WE FOUND THE THRESHOLD
            # print(f"FOUND THRESHOLD AT: {test_point}")
            return res, test_point
        else:
            if '+' in mode:
                return bin_search(coord_min, mid, mode)
            else:
                return bin_search(mid, coord_max, mode)
    else:
        if '+' in mode:
            return bin_search(mid, coord_max, mode)
        else:
            return bin_search(coord_min, mid, mode)

def find_center(guess):
    x_edges = [inf, inf]
    y_edges = [inf, inf]

    res, result = bin_search(guess, [int(1e9), guess[1]]) # x+
    if res == "CENTER":
        return res, result
    x_edges[1] = result[0]
    res, result = bin_search([-1 * int(1e9), guess[1]], guess, mode="x-")
    if res == "CENTER":
        return res, result
    x_edges[0] = result[0]
    res, result = bin_search(guess, [guess[0], int(1e9)], mode="y+")
    if res == "CENTER":
        return res, result
    y_edges[1] = result[1]
    res, result = bin_search([guess[0], -1 * int(1e9)], guess, mode="y-")
    if res == "CENTER":
        return res, result
    y_edges[0] = result[1]
    
    # print(f"x_edges: {x_edges}, y_edges: {y_edges}")
    
    pprint([(x_edges[1] + x_edges[0]) // 2, (y_edges[1] + y_edges[0]) // 2])
    res = input().strip()
    return res

case = 1
while case < cases:
    pprint([0,0])
    res = input().strip()
    points[(0,0)] = res
    if res == "CENTER":
        cases += 1
        continue
    elif res == "HIT":
        # print("EXECUTING FIND CENTER")
        res = find_center([0,0])
    else:
        # print("EXECUTING FIND CIRCLE")
        res, in_circle = find_circle()
        if res == "CENTER":
            cases += 1
            continue
        res = find_center(in_circle)
    cases += 1

sys.exit()
