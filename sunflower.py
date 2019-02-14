#you're the sunflower...
def printm(matrix):
    for i in matrix:
        for j in i:
            print(j, end = " ")
        print()
length = int(input())
matrix = []

for i in range(length):
    matrix.append(list(map(int,input().split(" "))))

if matrix[0][0] < matrix[0][1]:
    if matrix[0][0] < matrix[1][0]:
        printm(matrix)
    else:
        print("90 CCW")
        rotated = zip(*matrix[::-1]) #rotate clockwise
        for row in rotated:
            print(*row) 
else:
    if matrix[0][length-1] > matrix[1][length-1]: # 180 case
        print("180")
        for i in range(length-1,0,-1):
            for j in range(length-1, 0,-1):
                print(matrix[i][j],end = " ")
            print()
    else: # 90 case
        print("90")
        rotated = zip(*matrix[::-1])
        for row in rotated:
            print(*row)  
