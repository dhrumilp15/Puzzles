# k = 0
# for i in range(1, 10):
#     if "2" not in str(i):
#         k += 1
#         print(i)
# print(f"1-10: {k}")
# q = 0
# for i in range(10, 100):
#     if "2" not in str(i):
#         q += 1
#         print(i)
# print(f"10-100: {q}")
# p = 0
# for i in range(100, 1000):
#     if "2" not in str(i):
#         p += 1
#         print(i)
# print(f"100-1000: {p}")
# a = 0
# for i in range(1000, 10000):
#     if "2" not in str(i):
#         a += 1
#         print(i)
# total = k + q + p + a
# print(f"1000-10000: {a}")
# print(f"total: {total}")
# print(f"complement: {9999 - total}")
# s = 0
# for i in range(1, 10000):
#     if "2" in str(i):
#         s += 1
# print(f"direct: {s}")
import operator as op
from functools import reduce
import itertools


def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom  # or / in Python 2


x = list(map(lambda x: ''.join(x), set(itertools.permutations([*'MEMORIZE']))))
k = 0
for i in x:
    if i[0] == 'Z' and i[-1] == 'M':
        k += 1
print(k)
