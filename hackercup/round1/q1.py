import sys
import argparse

input = sys.stdin.readline
from collections import deque

def solve(args: dict):
    
    import os
    os.chdir(os.path.dirname(os.path.abspath(__file__)))
    with open(args['infile'], 'r') as f:
        read = f.read().strip().split('\n')
    dataiter = iter(read)
    def input():
        return next(dataiter)
    
    plans = int(input())
    outfile = args['outfile']
    open(outfile, 'w').close()
    
    for plan in range(1, plans+1):
        N, K, W = map(int, input().strip().split())
        L = list(map(int, input().strip().split()))
        A_L, B_L, C_L, D_L = map(int, input().strip().split())
        H = list(map(int, input().strip().split()))
        A_H, B_H, C_H, D_H = map(int, input().strip().split())
        #Initial Perimeter
        Pprod = 2 * (W + H[0])
        P = 2 * (W + H[0])
        useful = deque([(L[0], H[0])], maxlen=W)
        Parr = [P]

        for i in range(1, N):
            # Problem-defined way to get L and H
            if i >= K:
                Li = ((A_L * L[i-2] + B_L * L[i - 1] + C_L) % D_L) + 1
                L.append(Li)
                Hi = ((A_H * H[i-2] + B_H * H[i - 1] + C_H) % D_H) + 1
                H.append(Hi)
            else:
                Li = L[i]
                Hi = H[i]
            
            if Li > L[i-1] + W:
                P_i = 2 * (W + Hi)
                useful.clear()
            else:
                # Horizontal Perimeter
                P_i = 2 * (Li - L[i - 1])
                
                h = 0
                while useful and useful[0][0] < Li - W:
                    useful.popleft()
                
                if useful:
                    h = useful[0][1]
                
                # Vertical Perimeter
                if Hi > h:
                    P_i += 2 * (Hi - h)
                    useful.clear()
                else:
                    while useful and useful[-1][1] < Hi:
                        useful.pop()
            useful.append((Li, Hi))
            P_i += P
            Pprod *= P_i
            P = P_i
            Parr.append(P_i)
        Pprod %= 1000000007
        print(f"{Parr}: {Pprod}")
        # file i/o stuff
        with open(outfile, 'a') as f:
            f.write(f"Case #{plan}: {Pprod}\n")

ap = argparse.ArgumentParser(description='Perimetric chapter 1<--')
ap.add_argument('--infile', '-i', default="q1.txt")
ap.add_argument('--outfile', '-o', default="q1_output.txt")

if __name__ == "__main__":
    args = vars(ap.parse_args())
    print(args)
    solve(args)
