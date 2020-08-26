#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
#define endl "\n";

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    ifstream infile(argv[1]);            // input file
    ofstream outfile("q3outputcpp.txt"); // output file
    int plans;                           // # of cases
    infile >> plans;
    ll modNum = 1000000007; //big number to mod against

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
        // vector<ll> Parr{P};                 // Array of perimeters for debug use

        set<tiii> nonintersectLeft{tiii(L.at(0), 0, H.at(0)), tiii(L.at(0) + W.at(0), H.at(0), 0)};

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

            // Delta Perimeter (default 2 * (Wi + Hi))
            ll Pi = 2 * (Wi + Hi);

            // stores non-intersecting intervals of height deltas
            auto it = nonintersectLeft.lower_bound(tiii((int)Li, 0, 0));

            // Initial iterator position so that we can delete the range later on
            auto itR = it;

            // Previous SW coord for iterating
            int prevL = (int)Li;

            // Existing height at Li (default 0)
            int firstH = 0;

            // Existing Height at Li + Wi (default 0)
            int lastH = 0;

            // if it is the end, there are no rects that intersect this rectangle
            if (it != nonintersectLeft.end())
            {
                // Handles the vertical perimeter for coord Li
                firstH = get<1>(*it);
                Pi -= firstH;

                for (; it != nonintersectLeft.end(); ++it)
                {
                    if (get<0>(*it) > Li + Wi) // check if a height delta is > Li + Wi
                    {
                        break;
                    }

                    if (get<1>(*it) > 0) // The current rectangle is a continuation of itself or another rectangle
                    {
                        Pi -= 2 * (get<0>(*it) - prevL); // Overcounted horizontal perimeter
                    }
                    Pi -= abs(get<2>(*it) - get<1>(*it)); // delete any vertical perimeter with this height delta
                    prevL = get<0>(*it);                  // reset the previous L
                }
                if (it != nonintersectLeft.begin())
                {
                    auto previous = prev(it);
                    if (previous != it)
                    {
                        if (get<2>(*previous) > 0) // the last interval has continued OUT through Li + Wi
                        {
                            Pi -= 2 * (Li + Wi - prevL); // overcounted width
                            lastH = get<2>(*previous);
                            Pi -= lastH;
                        }
                    }
                }
            }

            nonintersectLeft.erase(itR, it);
            nonintersectLeft.emplace(tiii(Li, firstH, Hi));
            nonintersectLeft.emplace(tiii(Li + Wi, Hi, lastH));

            P += Pi;
            // Parr.push_back(P);
            Pprod = ((Pprod % modNum) * (P % modNum)) % modNum;
        }
        // cout << "Parr: [";
        // for (auto x : Parr)
        //     cout << x << ", ";
        // cout << "]\n";
        Pprod %= modNum;
        outfile << "Case #" << i << ": " << Pprod << "\n";
        // cout << Pprod << "\n";
    }
    return 0;
}