start = list(map(int,input().split(" ")))
end = list(map(int,input().split(" ")))
dist = int(input())
mindist = abs(end[0] - start[0]) + abs(end[1] - start[1])
if (dist - mindist) % 2 == 0 and dist - mindist >= 0:
    print("Y")
else:
    print("N")