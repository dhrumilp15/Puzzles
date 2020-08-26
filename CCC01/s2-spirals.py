import sys
from math import sqrt, ceil

input = sys.stdin.readline

# with open('spirals.in', "r") as f:
#     read = f.read().strip().split('\n')
# dataiter = iter(read)

# def input():
#     return next(dataiter)

# def print_board(board):
#     for row in board:
#         print(row)

start = int(input().strip())
end = int(input().strip())

dirs = [[1, 0], [0, 1], [-1, 0], [0, -1]]
diff = end - start + 1
rootdiff = sqrt(diff)

height = ceil(rootdiff)
width = round(rootdiff)

# top = diff - side**2
board = [[None for j in range(width)] for i in range(height)]

xpos = (height - 1) // 2 
ypos = (width - 1) // 2
# print(xpos, ypos)


# side = int(side)

currnum = start
sublength = 1
patindex = 0

while currnum != end + 1:
    for sub in range(sublength):
        if currnum > end:
            break
        board[xpos][ypos] = currnum
        xpos += dirs[patindex][0]
        ypos += dirs[patindex][1]
        currnum += 1
    patindex = (patindex + 1) % 4
    if patindex % 2 == 0:
        sublength += 1
        

#     diff = start - target + 1 # number of numbers
#     side = int(sqrt(diff))
#     top = diff - side**2
#     # print(diff, side, top)
#     board = [[None] * side for i in range(side)]
#     # print(board)
#     count = side ** 2 - 1
#     # row = 0
#     left = side**2
#     depth = 0

#     while left:
#         for wall in dirs:
#             if left:
#                 # print(depth, side - depth)
#                 for delta in range(depth, side - depth - 1):
#                     # print(f"delta: {delta}")
#                     if wall == "RIGHT":
#                         board[delta][side - 1 - depth] = count + target
#                     if wall == "DOWN":
#                         board[side - 1- depth][side - 1 -delta] = count + target
#                     if wall == "LEFT":
#                         board[side - 1- delta][depth] = count + target
#                     if wall == "UP":
#                         board[depth][delta] = count + target
#                     count -= 1
#                     left -= 1
#         depth += 1
    
#     maxlen = len(str(start))
    
    
# print_board(board)
for row in board:
    for value in row:
        if value:
            print(value, end = ' ')
        else:
            print(' ' * len(str(start)), end = ' ')
    # print(f"{num:>{maxlen}}", end = " ")
    print()