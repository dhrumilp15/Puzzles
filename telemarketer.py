number = ""
for i in range(4):
    number += str(input())
if number[0] in ["8", "9"] and number[1] == number[2] and number[3] in ["8",'9']:
    print("ignore")
else:
    print("answer")
        