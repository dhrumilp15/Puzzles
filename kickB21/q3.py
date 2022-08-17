import sys
from math import sqrt

input = sys.stdin.readline

T = int(input())

nums = [int(input()) for _ in range(T)]
biggest_num = max(nums)
sqrtnum = int(sqrt(biggest_num) + 1)
sqsqnum = int(sqrt(sqrtnum) + 1)

marked = [True] * (sqsqnum // 2 + 2) * (sqrtnum // 2 + 2)

for i in range(1, sqsqnum // 2 + 2):
    for j in range(2 * i * (i + 1), sqrtnum // 2 + 2, 2 * i + 1):
        marked[j] = False

amt = 1

primes = [2]
for i in range(1, sqrtnum // 2 + 1):
    if (marked[i]):
        primes.append(2 * i + 1)
        amt += 1

def binsearch(left, right, sqrtbig, primes):
    if left <= right:
        mid = (left + right) // 2

        if mid == 0 or mid == len(primes) - 1:
            return primes[mid], mid
        
        if primes[mid] == sqrtbig:
            return primes[mid - 1], mid - 1
        
        if primes[mid] < sqrtbig and primes[mid + 1] > sqrtbig:
            return primes[mid], mid
        
        if sqrtbig < primes[mid]:
            return binsearch(left, mid - 1, sqrtbig, primes)
        else:
            return binsearch(mid + 1, right, sqrtbig, primes)
    return 0,0

def checkprimality(n):
    for i in range(2, int(sqrt(n) + 1)):
        if n % i == 0:
            return False
    return True

for i in range(T):
    value = binsearch(0, len(primes) - 1, sqrt(nums[i]), primes);
    if (nums[i] % value[0] == 0):
        print(f"Case #{i + 1}: {nums[i]}")
    else:
        lastgoodnex = primes[value[1] - 1]
        nex = primes[value[1] - 1]
        # HOPING THIS IS FAST : )
        while value[0] * nex <= nums[i]:
            if checkprimality(nex) and nex != value[0]:
                lastgoodnex = nex
            nex += 1
        print(f"Case #{i + 1}: {value[0] * lastgoodnex}")

        # if value[1] - 1 >= 0 and value[1] + 1 < len(primes):
        #     smallr = value[0] * primes[value[1] - 1]
        #     biggr = value[0] * primes[value[1] + 1]
        #     if (biggr < nums[i]):
        #         print(f"Case #{i+1}: {biggr}")
        #     else:
        #         print(f"Case #{i+1}: {smallr}")
        # elif value[1] - 1 >= 0:
            
            
        #     print(f"Case #{i+1}: {smallr}")
        # else:
        #     biggr = value[0] * primes[value[1] + 1]
        #     print(f"Case #{i+1}: {biggr}")


        