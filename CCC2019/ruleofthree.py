class Node:
    def __init__(self):
        self.content = ""
        self.rule = 0
        self.position = 0
        self.children = []

def getsplits(string, size):
    full = []
    for i in range(len(string) - size + 1):
        full.append(string[i: i + size])
    return full

def createtree(nodes, nodemap):
    for node in nodes:
        for i in windowlens:
            nodemap.update({i:Node()})

# def findpath(nodes, level):
                  

subrules = {}
for i in range(3):
    rule = input().split(" ")
    subrules.update({rule[0] : rule[1]})
print(subrules)

windowlens = set()
for i, j in subrules.items():
    windowlens.add(len(i))
print(windowlens)

lastline = input().split(" ")
maxlevel = int(lastline[0])
initial = lastline[1]
nodemap = {}
initialnode = Node()
initialnode.content = initial
nodemap.update({initial : initialnode})
final = lastline[2]

createtree([initialnode], 0)