#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    ifstream infile(argv[1]); // input file
    int plans;                // # of cases
    infile >> plans;
    ofstream outfile("q2outputcpp.txt"); // output file
    ll modNum = 1000000007;              //big number to mod against
    for (int i = 1; i < plans + 1; i++)
    {
        // GET INPUT
        ll N, K; // N = # of rects, K = given # of rects
        infile >> N >> K;
        vector<ll> L; // SW coord of rects
        for (int k = 0; k < K; ++k)
        {
            ll number;
            infile >> number;
            L.push_back(number);
        }

        ll AL, BL, CL, DL;
        infile >> AL >> BL >> CL >> DL;
        vector<ll> W; // Widths of rects
        for (int k = 0; k < K; ++k)
        {
            ll number;
            infile >> number;
            W.push_back(number);
        }

        ll AW, BW, CW, DW;
        infile >> AW >> BW >> CW >> DW;
        vector<ll> H; // Heights of rectangles
        for (int k = 0; k < K; ++k)
        {
            ll number;
            infile >> number;
            H.push_back(number);
        }
        ll AH, BH, CH, DH;
        infile >> AH >> BH >> CH >> DH;
        // Input collection finished

        ll Pprod = 2 * (W.at(0) + H.at(0)); // Product of Perimeters
        ll P = 2 * (W.at(0) + H.at(0));     // Perimeter of the last rect

        vector<ll> Parr{P}; // Array of perimeters for debug use

        // Set of non-intersecting intervals
        set<pii> nonintersectLeft{pii(L.at(0), L.at(0) + W.at(0))};

        //Man I wished the debugger worked
        // cout << "Initial nonintersect: { ";
        // for (auto x : nonintersectLeft)
        // {
        //     cout << "(" << x.first << "," << x.second << "), ";
        // }
        // cout << "}\n";

        for (int j = 1; j < N; ++j)
        {
            ll Li, Hi, Wi; // Current L, H, W

            //Fb hacker cup's way of getting L, H, W beyond K
            if (j >= K)
            {
                Li = ((AL * L.at(j - 2) + BL * L.at(j - 1) + CL) % DL) + 1;
                L.push_back(Li);
                Hi = ((AH * H.at(j - 2) + BH * H.at(j - 1) + CH) % DH) + 1;
                H.push_back(Hi);
                Wi = ((AW * W.at(j - 2) + BW * W.at(j - 1) + CW) % DW) + 1;
                W.push_back(Wi);
            }
            else
            {
                Li = L.at(j);
                Hi = H.at(j);
                Wi = W.at(j);
            }
            // cout << "For (" << Li << ", " << Li + Wi << ") w/ height " << Hi << ":\n";
            // Change in perimeter
            ll Pi = 2 * Hi;

            // Gives us the interval with a SW coord of AT LEAST Li (or end())
            auto itL = nonintersectLeft.lower_bound(pii((int)Li, 0)); // returns an interval in [Li, inf) or end()
            // Stores the current iterator so that we can delete it later on
            auto itR = itL;

            //Previous SW coord for iterating
            int prevL = (int)Li;
            //Very first SW coord that overlaps with our rectangle to extend the set
            int firstL = (int)Li;

            // returns an interval with a starting pos in [0, Li) OR the same element
            auto previous = prev(itL);
            // Check if the previous rect overlaps the current rect
            if (itL != previous && previous->second >= Li)
            {
                // cout << "Previous: (" << previous->first << ", " << previous->second << ") is overlapping.\n";
                Pi -= 2 * Hi;
                firstL = previous->first;
                itR = previous;
                prevL = previous->second; // Gotcha: prevL can be beyond Li + Wi or equal to Li + Wi
            }

            // Check if the previous rect doesn't completely overlap the current rect
            if (prevL < Li + Wi)
            {
                if (itL == nonintersectLeft.end())
                {
                    Pi += 2 * (Li + Wi - prevL);
                }
                else if (itL->first > Li + Wi)
                {
                    Pi += 2 * (Li + Wi - prevL);
                }
                else
                {
                    for (; itL != nonintersectLeft.end(); ++itL)
                    {
                        if (itL->first > Li + Wi)
                        {
                            break;
                        }
                        Pi -= 2 * Hi;
                        Pi += 2 * (itL->first - prevL);
                        prevL = itL->second;
                    }
                    if (prevL <= Li + Wi)
                    {
                        Pi += 2 * (Li + Wi - prevL);
                    }
                }
                nonintersectLeft.erase(itR, itL);
                nonintersectLeft.emplace(firstL, max((int)(Li + Wi), prevL));
            }

            // cout << "nonintersect: { ";
            // for (auto x : nonintersectLeft)
            // {
            //     cout << "(" << x.first << "," << x.second << "), ";
            // }
            // cout << "}\n";

            Pi = Pi + P;
            Parr.push_back(Pi);
            Pprod = ((Pprod % modNum) * (Pi % modNum)) % modNum;
            P = Pi;
            // cout << "Parr: [";
            // for (auto x : Parr)
            //     cout << x << ", ";
            // cout << "]\n";
        }
        Pprod %= modNum;
        outfile << "Case #" << i << ": " << Pprod << "\n";
        cout << Pprod << "\n";
    }
    return 0;
}
