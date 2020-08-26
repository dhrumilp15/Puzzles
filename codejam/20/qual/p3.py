import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('p3.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

class Activity:
    def __init__(self, start, end, index):
        self.start = start
        self.end = end
        self.index = index

cases = int(input())

for case in range(1, cases + 1):
    acs = int(input())
    intervals = []
    order = [None] * acs
    end_c = -1
    end_j = -1
    time_to_index = dict()
    activity_to_partner = dict()
    for ac in range(acs):
        start, end = map(int, input().strip().split())
        act = Activity(start, end, ac)
        intervals.append(act)
    
    intervals.sort(key=lambda x: x.start)
    
    for interval in intervals:
        start, end = interval.start, interval.end
        print(start, end)
        if start >= end_c:
            activity_to_partner[interval] = 'C'
            start_c, end_c = start, end
        elif start >= end_j:
            activity_to_partner[interval] = 'J'
            start_j, end_j = start, end
        else:
            order = "IMPOSSIBLE"
            break
    else:
        for activity, partner in activity_to_partner.items():
            order[activity.index] = partner
        order = ''.join(order)
        
    print("CASE #{}: {}".format(case, order))