import sys

input = sys.stdin.readline

import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
with open('rhyme.in', 'r') as f:
    read = f.read().strip().split('\n')
dataiter = iter(read)
def input():
    return next(dataiter)

class Node:
    def __init__(self, char):
        self.char = char
        self.end = False
        self.children = []

def add(root, word):
    node = root
    for char in reversed(word):
        found = False
        for child in node.children:
            if child.char == char:
                node = child
                found = True
                break
        if not found:
            next_char = Node(char)
            node.children.append(next_char)
            node = next_char
    node.end = True

def count_unpaired(root):
    total = 0
    print(root.char)
    
    if root.end == True:
        total += 1
        print(f"Hit the end of the word at {root.char}")
    
    for child in root.children:
        total += count_unpaired(child)
        print(f"\ttotal: {total}")
    if total >= 2:
        return total - 2
    else:
        return total

cases = int(input())

for case in range(1, cases + 1):
    N = int(input())
    root = Node('*')
    for _ in range(N):
        add(root, input().strip())
    
    total = sum(count_unpaired(node) for node in root.children)
    print(total)
    # Trie created, now analyze
    print("Case #{}: {}".format(case, N-total))

