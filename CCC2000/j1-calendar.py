start, total = map(int,input().split(" "))
start -= 1

print("Sun Mon Tue Wed Thr Fri Sat")
for i in range(start):
    print("{:>3}".format(''), end = " ")

count = 1
while count - start <= total:
    if count - start > 0:
        if count % 7 == 0:
            print("{:>3}".format(count - start))
        elif (count - start) == total:
            print("{:>3}".format(count - start))
        else:
            print("{:>3}".format(count - start), end = " ")
    count += 1