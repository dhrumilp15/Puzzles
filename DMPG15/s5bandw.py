import sys

with open("s5in.txt","r") as f:
    data = f.read()
data = data.split('\n')
data = iter(data)

def input():
    return next(data)

def printlist(inp : list):
    for _ in inp:
        print(_)
# input = sys.stdin.readline

dimen, comm = map(int,input().split(" "))
board = [[1 for i in range(dimen)] for _ in range(dimen)]
flips = []

for _ in range(comm):
    x,y,w,h = map(int, input().split(" "))
    flips.append([(x,y),(w,h)])

# Naive, bruteforce solution
# for flip in flips:
    # print("Board right now:")
    # printlist(board)
#     lc = flip[0]
#     rc = flip[1]
#     for i in range(lc[1],lc[1] + rc[1]):
#         for j in range(lc[0], lc[0] + rc[0]):
#             board[i][j] = (board[i][j] + 1) % 2

# Attempt #2
for flip in flips:
    print("Board right now:")
    printlist(board)
    lc = flip[0]
    wh = flip[1]
    board[lc[1]][lc[0]] = 5
    



white = 0
# printlist(board)
for row in board:
    for value in row:
        if value == 0:
            white += 1

print(white)


# Attempt at a better one
# for flip in flips:
#     lc, rc = flip[0], flip[1]
#     if (lc[0] == rc[0]) or (lc[1] == rc[1]):
#         board[lc[0]][lc[1]] = board[lc[0]][lc[1]] + 1 % 2
#         board[rc[0]][rc[1]] = board[rc[0]][rc[1]] + 1 % 2
#     else:
#         board[lc[0]][lc[1]] = board[lc[0]][lc[1]] + 1 % 2
#         board[rc[0]][rc[1]] = board[rc[0]][rc[1]] + 1 % 2
#         board[lc[0]][rc[1]] = board[lc[0]][rc[1]] + 1 % 2
#         board[lc[0]][lc[1]] = board[lc[0]][lc[1]] + 1 % 2

