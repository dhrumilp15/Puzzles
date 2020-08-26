from math import inf

# Longest Increasing Path
class Solution:
    def solve(self, matrix):
        # Write your code here
        dplist = [[0 for _ in range(len(matrix[0]))] for __ in range(len(matrix))]

        def dfs(pos, plen, mlen):
            n = neighbours(pos)
            clen = 0
            for neigh in n:
                clen = plen + 1
                dfs(neigh, clen,mlen)
                if mlen[0] < clen:
                    mlen[0] = clen
                clen = 0


        def neighbours(pos):
            row = [-1,1,0,0]
            col = [0,0,-1,1]
            neighs = []
            for idx in range(4):
                if 0 <= pos[0] + row[idx] < len(matrix) and 0 <= pos[1] + col[idx] < len(matrix[0]):
                    if matrix[pos[0] + row[idx]][pos[1] + col[idx]] > matrix[pos[0]][pos[1]]:
                        neighs.append([pos[0] + row[idx], pos[1] + col[idx]])
            return neighs
        
        big = 0
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                mlen = [-int(1e9)]
                dfs([row,col], 0, mlen)
                ans = mlen[0]
                dplist[row][col] = max(dplist[row][col], ans)
                big = max(big, dplist[row][col])
        
        return big + 1
            
sol = Solution()
print(sol.solve([[1, 3, 5],
                [0, 4, 6],
                [2, 2, 9]]))
print(sol.solve([[63, 83, 27, 36],
                [98, 75, 18, 96]]))
