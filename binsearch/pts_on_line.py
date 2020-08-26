from math import gcd

class Solution:
    def solve(self, coordinates):

        res = 0

        # Write your code here
        for idx, coord in enumerate(coordinates[:-1]):
            overlap = 0
            lmax = 0
            slopedic = dict()

            for other in coordinates[idx + 1:]:
                deltay = other[1] - coord[1]
                deltax = other[0] - coord[0]

                if deltay == 0 and deltax == 0:
                    overlap += 1
                    continue
                
                gc = gcd(deltay, deltax)

                if gc != 0:
                    deltay //= gc
                    deltax //= gc

                if deltay == 0 and deltax < 0:
                    deltax *= -1
                if deltay < 0:
                    deltax *= -1
                    deltay *= -1

                if deltax not in slopedic:
                    slopedic[deltax] = {}
                if deltay not in slopedic[deltax]:
                    slopedic[deltax][deltay] = 0
                slopedic[deltax][deltay] += 1
                
                lmax = max(lmax, slopedic[deltax][deltay])
            res = max(res, lmax + overlap + 1)
        return res
sol = Solution()
print(sol.solve([[5, 1],
[7, 2],
[9, 3],
[0, 0],
[1, 1],
[5, 5],
[6, 6]]))
