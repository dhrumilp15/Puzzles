stream = int(input())
streams = []
for _ in range(stream):
    streams.append(int(input()))

nextLine = input()
while nextLine != "77":
    if nextLine == "99":
        index = int(input()) - 1
        percent = int(input()) / 100
        oldpwr = streams[index]
        streams[index] *= percent
        streams.insert(index + 1, oldpwr*(1 - percent))
    elif nextLine == "88":
        indic = int(input()) - 1
        streams[indic] += streams[indic + 1]
        del streams[indic + 1]
    nextLine = input()
print(*list(map(int,streams)))