import sys
input = sys.stdin.readline

tests = int(input())

for test in range(tests):
    mapseq = input().split(' ')
    mapseq.pop()
    seq = list(map(int, mapseq))

    a = False
    g = False

    if seq[0] + seq[2] == seq[1] * 2:
        a = True
    if seq[1]**2 == seq[0]*seq[2]:
        g = True
    
    if a == True and g == True:
        print('both')
    elif a == True:
        print('arithmetic')
    elif g == True:
        print('geometric')
    else:
        print('neither')