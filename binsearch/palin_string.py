# Longest Palindromic string
class Solution:
    def solve(self, s):
        # Write your code here
        mlen = 1
        start = 0
        slen = len(s)
        low = 0
        high = 0
        for letter in range(1, slen):
            low = letter - 1
            high = letter
            
            while low >= 0 and high < slen and s[low] == s[high]:
                if high - low + 1 > mlen:
                    start = low
                    mlen = high - low + 1
                low -= 1
                high += 1
            
            low = letter -1
            high = letter + 1

            while low >= 0 and high < slen and s[low] == s[high]:
                if high - low + 1 > mlen:
                    start = low
                    mlen = high - low + 1
                low -= 1
                high += 1
        # print(s[start: start + mlen])
        return mlen
sol = Solution()
print(sol.solve("mactacocatbook"))