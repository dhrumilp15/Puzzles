threeA = int(input())
twoA = int(input())
oneA = int(input())
threeB = int(input())
twoB = int(input())
oneB = int(input())
if threeA * 3 + twoA * 2 + oneA > threeB * 3 + twoB * 2 + oneB:
    print("A")
elif threeA * 3 + twoA * 2 + oneA < threeB * 3 + twoB * 2 + oneB:
    print("B")
else:
    print("T")