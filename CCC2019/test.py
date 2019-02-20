def getsplits(string, size):
    full = []
    for i in range(len(string) - size + 1):
        full.append(string[i: i + size])
    return full

string = "AB"
windowlens = set([1,2])
for i in windowlens:
    print(getsplits(string, i))