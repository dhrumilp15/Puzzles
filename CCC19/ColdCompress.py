lines = int(input())
allcodes = []
for i in range(lines):
    currline = input()
    allcodes.append(currline)

for i in allcodes:
    kewlkid = ""
    for pos, j in enumerate(i):
        if len(kewlkid) > 0:
            if j == kewlkid[0]:
                kewlkid += j
            else:
                print(len(kewlkid), end = " ")
                print(kewlkid[0], end = " ")
                kewlkid = j
            if pos == len(i) - 1:
                    print(len(kewlkid), end = " ")
                    print(kewlkid[0], end = " ")
        else:
            kewlkid += j
    print()