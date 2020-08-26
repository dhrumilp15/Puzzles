class Solution:
    def solve(self, edges):
        # Write your code here
        paths = {tuple(edge):0 for edge in edges}
        tree = {}
        for edge in edges:
            if edge[0] in tree:
                tree[edge[0]].append(edge[1])
            else:
                tree[edge[0]] = [edge[1]]
            if edge[1] in tree:
                tree[edge[1]].append(edge[0])
            else:
                tree[edge[1]] = [edge[0]]
        print(tree)
        
        def dfs(node, vis):
            vis[node] = True
            print(node)
            for child in tree[node]:
                if [node, child] in edges:
                    paths[(node, child)] += 1
                if child not in vis:
                    dfs(child, vis)
        
        for node2 in tree:
            dfs(node2,{})
            print()
        
        print(paths)
        


sol = Solution()
sol.solve([[0,1],[1,2],[0,3]])