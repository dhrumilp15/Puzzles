primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499]
primeset = set(primes)
v = {0: False, 1: True}

def finddivisors(num):
    k = []
    i = 0
    end = len(primes)
    for i in primes:
        if num % i == 0:
            k.append(i)
    return k


for num in range(2, 300):
    if num in primeset:
        v[num] = True
    else:
        if v[num - 1] == False:
            v[num] = True
        else:
            for i in finddivisors(num):
                if v[num - i] == False:
                    v[num] = True
                    break
            else:
                v[num] = False

for obj, val in v.items():
    print(obj, val)
