import sys
input = sys.stdin.readline

input()

seq = list(map(int,input().strip().split(' ')))
# print(seq)
numbers = {}
for num in seq:
    if num in numbers:
        numbers[num] += 1
    else:
        numbers.update({num : 1})
maxmode = max(numbers.items(), key = lambda x: x[1])[1]

a = []

for key, value in numbers.items():
    if value == maxmode:
        a.append(int(key))
print(' '.join(map(str,sorted(a))))
