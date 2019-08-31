start = int(input()); end = int(input())

# flippable = [1, 8, 0]
# nonflip = [2,3,4,5,7]
flipable = {'1':'1', '8':'8', '0':'0', '6':'9', '9':'6'}

flip = 0

for testnum in range(start, end + 1):
    testdig_arr = [d for d in str(testnum)]
    newstr = ""
    for digit in testdig_arr:
        if digit in flipable.keys():
            newstr = str(flipable[digit]) + newstr
        else:
            break
    if newstr == str(testnum):
        flip += 1
    # if testnum in flippable:
    #     flip += 1
    # if not any(a in set(int(i) for i in str(testnum)) for a in nonflip):
    #     print(testnum)
    #     curr = list(str(testnum))
    #     halflen = int(len(curr) / 2)
    #     for index in range(halflen):
    #         if curr[index] == '9':
    #             curr[index] = '6'
    #         elif curr[index] == '6':
    #             curr[index] = '9'
    #     curr = curr.join('')
    #     if curr[:halflen] == curr[halflen:][::-1] or curr[:halflen] == curr[(halflen + 1):][::-1]:
    #         flip += 1
print(flip)



    
    