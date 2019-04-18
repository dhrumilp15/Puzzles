class Node:
    def __init__(self, position):
        self.position = position
        self.moves = []
        self.children = []

def goableplaces(node, nodepos, pastplaces):
    pastplaces.add(node.position)
    for nodes in node.children:
        pastplaces.add(nodes.position)

        
def findpath(nodes, level):
    level += 1
    child = []
    for node in nodes:
        

cases = int(input())
for case in range(1, cases + 1):
    Rows,columns = map(int, input().split(" "))
    
    nodedic = {}
    for i in range(1, rows + 1):
        for j in range(1, columns + 1):
            nodedic.update({(i,j) : Node([i,j])})
    
    for nodepos, node in nodedic:
        for row in range(1,rows + 1):
            for col in range(1, columns + 1):
                if not ((nodepos[0] == row) or (nodepos[1] == col) 
                       or (nodepos[0] - nodepos[1] == row - col)
                       or (nodepos[0] + nodepos[1] == row + col)):
                    node.children.append(nodedic[(row,col)])
    
    for nodepos, node in nodedic:
        pastplaces = set()
        goableplaces(node, nodepos, pastplaces)

        if len(pastplaces) != rows*columns:
            print("Case #{}: IMPOSSIBLE".format(case))
            break
        else:
            
        
