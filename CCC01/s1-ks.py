import sys
input = sys.stdin.readline

hand = input()
points = 0
cards = {'C': [[], 0], 'D' : [[], 0], 'H': [[], 0], 'S': [[], 0]}
state = 'C'
for letter in hand:
    if letter == 'D':
        state = 'D'
        break
    elif letter == 'H':
        state = 'H'
        break
    elif letter == 'S':
        state = 'S'
        break
    else:
        cards[state][0].append(letter)
        if letter == 'A':
            points += 4
            cards[state][1] += 4
        elif letter == 'K':
            points += 3
            cards[state][1] += 3
        elif letter == 'Q':
            points += 2
            cards[state][1] += 2
        elif letter == 'J':
            points += 1
            cards[state][1] += 1

for key, value in cards:
    if len(value) == 0:
        points += 3
        cards[key][1] += 3
    elif len(value) == 1:
        points += 2
        cards[key][1] += 2
    if len(value) == 2:
        points += 1
        cards[key][1] += 1

print('Cards Dealt',end = "")
print(' '*14,end = "")
print('Points')
for key, value in cards:
    if key == 'C':
        print('Clubs',end="")
    elif key == 'D':
        print('Diamonds',end = "")
    elif key == 'H':
        print('Hearts',end="")
    elif key == 'S':
        print('Spades',end = "")
    print(' '.join(value[0]))