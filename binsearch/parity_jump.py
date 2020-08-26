from collections import deque

class Solution:
    def solve(self, nums):
        # Write your code here

        def bfs(index, nums):
            visited = set([index])
            queue = deque([(index, 0)])
            
            while queue:
                curr, length = queue.popleft()
                possib = []
                if 0 <= curr - nums[curr] < len(nums) and curr - nums[curr] not in visited:
                    possib.append(curr - nums[curr])
                
                if 0 <= curr + nums[curr] < len(nums) and curr + nums[curr] not in visited:
                    possib.append(curr + nums[curr])
                
                for possible in possib:
                    if nums[possible] % 2 != nums[index] % 2:
                        return length +1
                    visited.add(possible)
                    queue.append((possible, length + 1))
            return -1

        final = [-1] * len(nums)
        for index in range(len(nums)):
            final[index] = bfs(index, nums)
        return final

        
                    
solution = Solution()

found = solution.solve([5, 1, 2, 3, 4, 7, 4, 5])
print(found)
print(found == [-1, 1, 1, 1, 1, -1, 2, 1])

found = solution.solve([14, 29, 94, 63, 55, 29, 35, 31, 15, 6, 34, 52, 74, 31, 58, 92, 96, 80, 36, 99, 39, 74, 52, 50, 36, 81, 11, 23, 85, 58, 84, 54, 98, 3, 52, 67, 51, 20, 26, 76, 15, 53, 44, 43, 64, 63, 2, 23, 45, 76, 33, 8, 33, 3, 6, 57, 93, 96, 88, 29, 71, 92, 81, 6, 97, 48, 94, 17, 20, 74, 51, 20, 30, 54, 90, 88, 70, 76, 67, 92, 69, 20, 47, 37, 64, 27, 80, 22, 100, 23, 65, 65, 44, 43, 67, 58, 66, 95, 31, 10])
print(found)
print(found == [5, 1, -1, 1, 2, 1, 5, 1, 1, 1, -1, -1, 2, 1, 4, -1, -1, 1, 2, -1, 2, 4, -1, 2, 1, -1, 1, 2, -1, 4, -1, 1, -1, 1, 2, -1, 1, 2, 1, -1, -1, 4, 2, 1, -1, -1, 1, 1, 2, -1, 1, 1, 2, 2, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, 2, -1, 1, 1, -1, -1, 1, 3, 1, -1, -1, 1, 1, 1, -1, 1, -1, -1, 1, 1, 1, 1, 3, -1, 1, -1, 2, 1, 2, 3, 3, -1, 1, 2, 1])
