import sys
input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('q2.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)


# def recurse_helper(N, K, P):


cases = int(input())
for case in range(1, cases + 1):
    N, K, P = map(int, input().strip().split())
    bigstack = []
    stacks = []
    max_sum = 0
    for stack in range(N):
        plates = list(map(int, input().strip().split()))
        bigstack.extend(plates)
        stacks.append(plates)
    
    print(bigstack, stacks)
    search = P
    prev_sum = 0
    curr_sum = sum(bigstack[search - P: search])
    print("Started as {}".format(curr_sum))
    while search < N * K:
        max_sum = max(max_sum, curr_sum)
        mod = search % K
        add = bigstack[search]
        curr_sum += add
        drop = bigstack[K - mod]
        curr_sum -= drop
        print("Added {}, dropped {}, now {}".format(add, drop, curr_sum))
        search += 1
    max_sum = max(max_sum, curr_sum)
    print("Case{}: {}".format(case, max_sum))

