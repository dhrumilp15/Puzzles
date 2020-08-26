import sys

# input = sys.stdin.readline

def complement(guess):
    return [1 if item == 0 else 0 for item in guess]

def candr(guess):
    return complement(reversed(guess))

cases, bits = map(int, input().strip().split())
case = 0
while case < cases:
    queries = 1
    guess = [None] * bits
    ask = 1
    while queries <= 150:
        print(ask)
        sys.stdout.flush()

        recv = int(input())
        if queries % 10 == 1 and queries > 1: # We have at least 10 bits in the array and we've now just received a bit following a qf
            pass
        guess[ask - 1] = recv

        # If the entire array is full, send our value
        if all([item is not None for item in guess]): # Never need to worry about B = 0
            print(''.join(map(str, guess)))
            sys.stdout.flush()
            res = input()
            break
        ask = (ask + 1) % bits
        queries += 1
    case += 1
sys.exit()
