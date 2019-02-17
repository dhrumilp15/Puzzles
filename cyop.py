class Node:
    def __init__(self,value):
        self.value = value
        self.children = []
def reachablepages(node, pages):
    if node.value not in pages:
        pages.add(node.value)
        for i in node.children:
            reachablepages(i,pages)

def shortpath(nodes, level):
    level += 1
    child = []
    for node in nodes:
        if len(node.children) == 0:
            return level
        else:
            for i in node.children:
                child.append(i)
    return shortpath(child,level)

booksize = int(input())
pagemap = {}

for i in range(1, booksize + 1):
    pagemap[i] = Node(i)

for i in range(1, booksize + 1):
    inputline = list(map(int,input().split(" ")))
    for j in range(1, inputline[0] + 1):
        pagemap[i].children.append(pagemap[inputline[j]])

pages = set()
reachablepages(pagemap[1], pages)
if len(pages) == booksize:
    print("Y")
else:
    print("N")
print(shortpath(pagemap[1],0))
