import math

def solution(total_lambs):
    min_hench = int(math.log(total_lambs) / math.log(2))
    print(f"for {total_lambs}, we get {min_hench}")
    if total_lambs - min_hench >= 2**(min_hench-2) + 2**(min_hench - 1):
        min_hench += 1



def sum_fib(total_sum):
    if total_sum == 1:
        return 1
    elif total_sum == 2:
        return 1
    elif total_sum == 3:
        return 1
    elif total_sum == 4:
        return 3

    depth = 0
    n_2 = 1
    n_1 = 1
    total = 0
    while total < total_sum:
        print(f"BEFORE: total: {total} n_1: {n_1}, n_2: {n_2}")
        total += (n_1 + n_2)
        n_2 = n_1
        n_1 = total
        print(f"AFTER: total: {total}, n_1: {n_1}, n_2: {n_2}")
        depth += 1
    return depth

print(sum_fib(100))