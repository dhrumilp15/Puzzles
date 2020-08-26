import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('floorplan.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

supply = int(input().strip())
rows = int(input().strip())
cols = int(input().strip())
# print(rows, cols)
plan = [[None for col in range(cols)] for row in range(rows)]
# print(len(plan[0]))

corners = []

for row in range(rows):
    plan[row] = list(input().strip())
    # for col, tile in enumerate(line):
    #     plan[row][col] = tile
    #     if tile == '.':
    #         if col != 0 and row != 0:
    #             if plan[row - 1][col] == 'I' and plan[row-1][col-1] == 'I' and plan[row][col - 1] == 'I':
    #                 corners.append((row,col))
    #         elif col != 0:
    #             if plan[row][col - 1] == 'I':
    #                 corners.append((row,col))
    #         elif row != 0:
    #             if plan[row-1][col] == 'I':
    #                 corners.append((row,col))
# print(corners)
# print(plan)
seen = set()
rooms = [0] * rows*cols
roomcount = 0
for row in range(rows):
    for col in range(cols):
        if (row,col) not in seen and plan[row][col] != 'I':
            # print(f"Start: ({row}, {col})")
            queue = []
            queue.append((row,col))
            seen.add((row,col))
            rooms[roomcount] += 1
            while queue:
                current = queue.pop(0)
                surrounding = []
                if current[0] - 1 >= 0:
                    if plan[current[0] - 1][current[1]] != 'I' and (current[0] - 1, current[1]) not in seen:
                        surrounding.append((current[0] - 1, current[1]))
                if current[1] - 1 >= 0:
                    if plan[current[0]][current[1] - 1] != 'I' and (current[0], current[1] - 1) not in seen:
                        surrounding.append((current[0], current[1] - 1))
                
                if current[0] + 1 < rows:
                    if plan[current[0] + 1][current[1]] != 'I' and (current[0] + 1, current[1]) not in seen:
                        surrounding.append((current[0] + 1, current[1]))
                if current[1] + 1 < cols:
                    if plan[current[0]][current[1] + 1] != 'I' and (current[0], current[1] + 1) not in seen:
                        surrounding.append((current[0], current[1] + 1))
                # print(f"\tsurrounding: {surrounding}")
                for tile in surrounding:
                    queue.append(tile)
                    # print(f"\tTravels to {tile}")
                    rooms[roomcount] += 1
                    seen.add(tile)
            roomcount += 1
rooms = rooms[:roomcount]
# print(rooms)
sortedrooms = sorted(rooms, reverse = True)
# print(sortedrooms)
furnished = 0
# print(supply)
for room in sortedrooms:
    if supply - room >= 0:
        furnished += 1
        supply -= room
    else:
        break
leftover = supply

# print(furnished, leftover)
message = ""
if furnished == 1:
    message += "1 room"
else:
    message += f"{furnished} rooms"

# if leftover:
message += f", {leftover} square metre(s) left over"
# print(supply)
# print(sortedrooms)
# print(furnished, leftover)
print(message)