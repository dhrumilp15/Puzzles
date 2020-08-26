from fractions import gcd

# print(gcd(2,1))

def solution(x, y):
    ans = solve(x,y)
    return str(ans)

def solve(x,y):
    M = int(x)
    F = int(y)
    if M == 1 and F == 1: # base case
        return 0
    if M == 1 or F == 1: # simple case?
        return max(M,F) - 1
    
    if gcd(M,F) != 1: # have to be coprime
        # print("Failed for M:{}, F:{}".format(M,F))
        return "impossible"
    
    num_jumps = max(M,F) // min(M,F)
    # Switching the x and y shouldn't be a problem if we jump across the diagonal since the problem is symmetric... (Hopefully)
    print("Jumping from ({}, {}) to ({},{})".format(M,F,min(M,F), max(M,F) % min(M,F)))
    return num_jumps + solve(min(M,F), max(M,F) % min(M,F))
    # return 1 + solution(min(M,F), max(M,F) - min(M,F))

print(solution("2","1"))
print(solution("11","8"))
print(solution("4","7"))

"""
 |123456789
-+---------
1|012345678
2|1X2X3X4X5
3|22X33X44X
4|3X3X4X4X5
5|4334X5445
6|5XXX5X6XX
7|644446X75
8|7X4X4X7X8
9|85X55X58X
"""