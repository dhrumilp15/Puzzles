# Top view of a tree

class Tree:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def solve(self, root):
        l_max = int(1e9)
        r_max = -int(1e9)
        left = []
        right = []
        cols = {}


        def r_solve(root, dist):
            if dist not in cols:
                cols[dist] = [root.val]
            else:
                cols[dist].append(root.val)
            if root.left is not None:
                r_solve(root.left, dist - 1)
            if root.right is not None:
                r_solve(root.right, dist + 1)
        r_solve(root, 0)
        lis = []
        
        for col in cols:
            lis.append((cols[col][0],col))
        lis.sort(key=lambda x : x[1])
        return lis



            



