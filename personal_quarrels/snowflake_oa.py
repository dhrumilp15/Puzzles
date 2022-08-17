# dev-tester integration

def formTeam(d, t, q):
    ans = []
    maxSize = max(q)
    hMap = {i: 0 for i in range(0, maxSize+1)}
    res = []
    helper(res, d, t, d, t, maxSize, "", hMap)
    # print(hMap.values())
    for size in q:
        ans.append(hMap[size])
    
    return ans

def helper(res, d, t, maxD, maxT, size, currPerm, hMap):
    if size >= len(currPerm):
        hMap[len(currPerm)] += 1
    if size == len(currPerm):
        # print(currPerm, d, t, len(currPerm))
        res.append(currPerm)
    else:
        if currPerm == "" or d > 1:
            helper(res, d - 1, maxT, maxD, maxT, size, currPerm+'D', hMap)
        if currPerm == "" or t > 1:
            helper(res, maxD, t - 1, maxD, maxT, size, currPerm + 'T', hMap)