import sys

# input = sys.stdin.readline

import os
# os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open(sys.argv[-1], 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)


def main():
    N, D = map(int, input().strip().split())
    nums = list(map(int, input().strip().split()))
    for _ in range(D):
        k = int(input())
        F = sum(nums[:k])
        S = sum(nums[k:])
        if F >= S:
            print(F)
            nums = nums[k:]
        else:
            print(S)
            nums = nums[:k]

if __name__ == "__main__":
    main()