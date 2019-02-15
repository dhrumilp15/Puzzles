#you're the sunflower...
length = int(input())
matrix = []

for i in range(length):
    matrix.append(list(map(int,input().split(" "))))

if matrix[0][0] < matrix[0][1]:
    if matrix[0][0] < matrix[1][0]:
        #print("0")
        for i in matrix:
            for j in i:
                print(j, end = " ")
            print()
    else:
        #print("90 CCW")
        for i in range(length):
            for j in range(length-1,-1,-1):
                print(matrix[j][i], end = " ")
            print()

else:
    if matrix[0][length-1] > matrix[1][length-1]: # 180 case
        #print(180)
        for i in range(length-1,-1,-1):
            for j in range(length-1, -1,-1):
                print(matrix[i][j],end = " ")
            print()
    else: # 90 case
        #print("90")
        for i in range(length-1,-1,-1):
            for j in range(length):
                print(matrix[j][i], end = " ")
            print()
