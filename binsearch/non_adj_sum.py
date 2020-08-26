# Largest sum of non-adjacent numbers

class Solution:
    def solve(self, nums):
        included = 0
        excluded = 0
        
        for num in nums:
            n_excl = max(excluded, included)
            
            included = excluded + num
            excluded = n_excl
        return max(excluded, included)

sol = Solution()
print(sol.solve([2, 4, 6, 2, 5]))
print(sol.solve([-10, -22, -18, -3, -100]))
print(sol.solve([5, 1, 1, 5]))