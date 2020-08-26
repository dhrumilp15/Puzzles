import sys

input = sys.stdin.readline

# with open('calls.in', 'r') as f:
#     read = f.read().strip().split('\n')
# dataiter = iter(read)
# def input():
#     return next(dataiter)

# print("-".isalpha())
# N = int(input().strip())
# chars = 0
# while chars <= 10:
#     phonenum = input().strip()
#     message = ""
#     for char in phonenum:
#         if char.isalpha():
flag = input().strip()
nummap = {}
while flag != '-1':
    given = input().strip().split()
    print(f"given: {given}")
    nummap[given[0]] = given[1]
    flag = given
print(nummap)