from math import log, ceil, floor

def solution(n):
    pellets = long(n)
    if pellets <= 1:
        return 0
    return str(solve(pellets))

def solve(n):
    total = 0
    while n > 1:
        if n==3:
            total += 2
            break

        if n & 1 == 0:
            # ASSUME: You ALWAYS divide an even number by 2
            total += 1
            n >>= 1
        else:
            bigg = n + 1
            good_bigg = 0
            while bigg & 1 == 0:
                bigg >>= 1
                good_bigg += 1
            
            small = n - 1
            good_small = 0
            while small & 1 == 0:
                small >>= 1
                good_small += 1
            
            if good_bigg < good_small:
                total += 1
                n -= 1
            else:
                total += 1
                n += 1
    return total

print(solution('15'))
print(solution('4'))
# print(solution(input()))
# print('9' * 10**309)