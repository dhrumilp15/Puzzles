length = int(input())
if not length == 0:
    yes = input()
    tod = input()
carbois = 0
for i in range(length):
    if yes[i] == 'C' and tod[i] == 'C':
        carbois += 1
print(carbois)