#IP address combinations
class Solution:
    def solve(self, ip):
        # Write your code here
        iplen = len(ip)
        start = 0
        end = 0
        word = []
        iplist = []
        parts = 0
        
        def rsolve(ip):
            nonlocal word, iplen,start,end,iplist
            while parts < 4:
                if ip[start] == "0":
                    word.append(ip[start])
                    parts += 1
                else:
                    for i in range(1,4):
                        rsolve()
