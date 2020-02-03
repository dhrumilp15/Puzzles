from copy import deepcopy

class Node:
	def __init__(self, position):
		self.position = position
		self.children = []


def goableplaces(node, pastplaces):
	pastplaces.add(node.position)
	for childnode in node.children:
		if childnode.position not in pastplaces:
			pastplaces.add(childnode.position)
			goableplaces(childnode, pastplaces)

def movesbuilder(node,nodedic):
	stack = []
	for position, node in nodedic.items():
		visited = {}
		for pos, nod in nodedic.items():
			visited.update({pos: False})
		visited[position] = True
		stack.append(((position,), visited))
	while stack:
		moves, visited = stack.pop()
		if len(moves) == len(nodedic):
			return moves
		for position, node in nodedic.items():
			currchildren = []
			for child in nodedic[moves[-1]].children:
				currchildren.append(child.position)
			if position in currchildren and not visited[position]:
				vis = deepcopy(visited)
				vis[position] = True
				stack.append((moves+(position,), vis))


cases = int(input())
for case in range(1, cases + 1):
	rows, columns = map(int, input().split(" "))

	nodedic = {}
	for i in range(1, rows + 1):
		for j in range(1, columns + 1):
			nodedic.update({(i, j): Node((i, j))})

	for nodepos, node in nodedic.items():
		for row in range(1, rows + 1):
			for col in range(1, columns + 1):
				if not ((nodepos[0] == row) or (nodepos[1] == col) or (nodepos[0] - nodepos[1] == row - col) or (nodepos[0] + nodepos[1] == row + col)):
					node.children.append(nodedic[(row, col)])


	for nodepos, node in nodedic.items():
		pastplaces = set()
		goableplaces(node, pastplaces)
		if len(pastplaces) != rows * columns:
			print("Case #{}: IMPOSSIBLE".format(case))
			break
		else:
			print("Case #{}: POSSIBLE".format(case))
			moves = movesbuilder(node,nodedic)
			for pos in moves:
				print("{} {}".format(pos[0], pos[1]))
			break