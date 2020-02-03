n = input()
shift = int(input())
final = int(n)
for i in range(shift):
    n += "0"
    final += int(n)
print(final)