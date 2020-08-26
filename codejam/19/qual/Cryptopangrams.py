from math import gcd
import sys

input = sys.stdin.readline

# with open("crypto2.in", "r") as f:
#     data = f.read().strip().split('\n')
# dataiter = iter(data)

# def input():
#     return next(dataiter)

cases = int(input().strip())

def numtostr(plain):
    plain = sorted(list(set(plain)))
    alphabet = {}
    letter = ord('A')
    for text in plain:
        alphabet.update({text : chr(letter)})
        letter += 1
    return alphabet

for case in range(1, cases + 1):
    largest, allnum = map(int, input().strip().split())
    crypted = list(map(int, input().strip().split()))
    plain = []
    common = 0
    for product in range(1, allnum):
        if not plain: # We have not started
            if crypted[product] == crypted[product - 1]:
                common += 1

            elif common:
                common += 1
                prevprime = gcd(crypted[product - 1], crypted[product])
                unzipped = [None] * (common + 1)
                unzipped[-1] = prevprime
                pprime = prevprime
                for cproduct in range(common):
                    pprime = crypted[product - (1 + cproduct)] // pprime
                    unzipped[common - (1 + cproduct)] = pprime
                plain.extend(unzipped)
                common = 0
                prevprime = crypted[product] // prevprime
            
            else:
                prevprime = gcd(crypted[product - 1], crypted[product])
                plain.append(crypted[0] // prevprime)
                plain.append(prevprime)
                prevprime = crypted[product] // prevprime
        else: # We have already started
            plain.append(prevprime)
            prevprime = crypted[product] // prevprime
    plain.append(prevprime)

    alphabet = numtostr(plain)
    message = ""
    for plaintext in plain:
        message += alphabet[plaintext]
    print("Case #{}: {}".format(case, message))
