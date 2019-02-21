lines = int(input())
codebois = []
for i in range(lines):
    currline = input().split(" ")
    currline[0] = int(currline[0])
    codebois.append(currline)

for i in codebois:
    print(i[1] * i[0])