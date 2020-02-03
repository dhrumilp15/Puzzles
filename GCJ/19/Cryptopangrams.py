from math import gcd
import sys
# import os

input = sys.stdin.readline

# with open(os.path.join(os.getcwd(), "gcj/19/crypto2.in"), "r") as f:
# with open("crypto2.in", "r") as f:
#     data = f.read().strip().split('\n')
# dataiter = iter(data)

# def input():
#     return next(dataiter)

cases = int(input().strip())

# def find_prime(product):
#     for casenum in range(2, ceil(sqrt(product)) + 1):
#         if product % casenum == 0:
#             return casenum, product // casenum

def numtostr(plain):
    plain = sorted(list(set(plain)))
    alphabet = {}
    letter = 65
    for text in plain:
        alphabet.update({text : chr(letter)})
        letter += 1
    return alphabet

for case in range(1, cases + 1):
    largest, allnum = map(int, input().strip().split())
    crypted = list(map(int, input().strip().split()))
    # print(len(crypted))
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
                # print(f"prevprime: {prevprime}")
            else:
                prevprime = gcd(crypted[product - 1], crypted[product])
                plain.append(crypted[0] // prevprime)
                plain.append(prevprime)
                prevprime = crypted[product] // prevprime
                # print(f"prevprime: {prevprime}")
        else: # We have already started
            # print(f"prevprime: {prevprime}")
            plain.append(prevprime)
            prevprime = crypted[product] // prevprime
        # if plain:
        #     print(plain)
        # else:
        #     print(common)
    plain.append(prevprime)
    # print(plain)

    alphabet = numtostr(plain)
    message = ""
    for plaintext in plain:
        message += alphabet[plaintext]
    print(f"Case #{case}: {message}")
    