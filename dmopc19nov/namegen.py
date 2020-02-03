import sys

input = sys.stdin.readline
alphalen = 26

def fact(n):
    if n == 0:
        return 1
    if n == 1:
        return n
    else:
        return n * fact(n-1)


N, k = map(int, input().strip().split(' '))
factN = fact(N)

def calccombo(given, dic):
    dic[given] += k
    ans = factN // prod(list(map(fact,dic.values())))
    dic[given] -= k
    return ans

def prod(prodlist):
    product = 1
    for i in prodlist:
        product *= i
    return product

chardic = {}
chars = list(input().strip())
distinctg = 0
for char in chars:
    if char != '*':
        if char in chardic:
            chardic[char] += 1
        else:
            chardic.update({char : 1})
            distinctg += 1

def kone(dic, given = None):
    if given:
        dic[given] += 1
    total = 0
    distinctk = factN * (alphalen - len(dic.keys())) // prod(list(map(fact, dic.values())))
    total += distinctk
    for key, value in dic.items():
        total += calccombo(key, dic)
    if given:
        dic[given] -= 1
    return int(total)
if k == 0:
    print(int(factN / prod(list(map(fact, chardic.values())))))
elif k == 1:
    print(kone(chardic))
elif k == 2:
    if N == 2:
        print(alphalen**2)
    else:
        distinctk = ((alphalen - distinctg) * (alphalen - 1 - distinctg) // 2) * factN // prod(list(map(fact, chardic.values())))
        total = 0
        total += distinctk
        bgin = 0
        for key, value in chardic.items():
            chardic[key] += 1
            for ke,val in list(chardic.items())[bgin:]:
                chardic[ke] += 1
                total += factN // prod(list(map(fact, chardic.values())))
                chardic[ke] -= 1
            total += factN * (alphalen - distinctg) // prod(list(map(fact, chardic.values())))
            chardic[key] -= 1
            bgin += 1
        total += (factN // (2 * prod(list(map(fact,chardic.values()))))) * (alphalen - distinctg)
        
        print(int(total))