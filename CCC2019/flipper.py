H, V = 0, 0
ref = input()
for i in ref:
    if i == "H":
        H+= 1
    else:
        V += 1
H %= 2
V %= 2

if H == 0 and V == 0:
    print("1 2")
    print("3 4")
elif H == 1 and V == 0:
    print("3 4")
    print("1 2")
elif H == 0 and V == 1:
    print("2 1")
    print("4 3")
else:
    print("4 3")
    print("2 1")
