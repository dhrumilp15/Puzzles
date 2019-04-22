dist = list(map(int, input().split(" ")))

for i in range(5):
    for j in range(5):
        if not i == j:
            cdist = 0
            if i > j:
                for k in dist[j:i]:
                    cdist += k
                print(cdist, end = " ")
            else:
                for k in dist[i:j]:
                    cdist += k
                print(cdist, end = " ")
        else:
            print("0", end = " ")
    print()