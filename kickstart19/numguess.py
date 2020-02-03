import sys

input = sys.stdin.readline
def binsearch(a,b):
    middle = (a + b) // 2
    print(middle)
    sys.stdout.flush()
    res = input()
    if res == "TOO_BIG":
        binsearch(a, middle - 1)
    elif res == "TOO_SMALL":
        binsearch(middle + 1, b)
    elif res == "CORRECT":
        return

T = int(input())
for _ in range(T):
    exmin, inmax = map(int, input().split(" "))
    tries = int(input())
    binsearch(exmin + 1, inmax)