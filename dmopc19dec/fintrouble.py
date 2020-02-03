import sys

input = sys.stdin.readline

N, M, Q = map(int, input().strip().split())

events = list(map(int, input().strip().split()))

for case in range(Q):
    day1, day2 = map(int, input().strip().split())
    scenario = events[day1-1:day2]

    borrow = 0
    money = M
    
    for day in scenario:
        money += day
        if money < 0:
            borrow += 1
            money = 0
    
    print(' '.join([str(money), str(borrow)]))