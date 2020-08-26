def solution(numbers):
    cache = [0] * len(numbers) # number of other numbers in the list that divides the number at that index
    triples = 0
    for i in range(len(numbers)):
        for j in range(i):
            if numbers[i] % numbers[j] == 0:
                cache[i] += 1
                triples += cache[j]
    return triples
print(solution([1,1,1]))