#include <bits/stdc++.h>
#include <fstream>

using namespace std;
int main(int argc, char *argv[])
{
    ifstream infile(argv[1]);
    int plans;
    infile >> plans;
    ofstream outfile("q1outputcpp.txt");
    unsigned long long modNum = 1000000007;
    for (int i = 0; i < plans; i++)
    {
        // printf("\nCase #%d\n", i + 1);
        long long N, K, W;
        infile >> N >> K >> W;
        vector<long long> L;
        for (int k = 0; k < K; k++)
        {
            long long number;
            infile >> number;
            L.push_back(number);
        }

        long long AL, BL, CL, DL;
        infile >> AL >> BL >> CL >> DL;
        vector<long long> H;
        for (int l = 0; l < K; l++)
        {
            long long number;
            infile >> number;
            H.push_back(number);
        }
        long long AH, BH, CH, DH;
        infile >> AH >> BH >> CH >> DH;

        unsigned long long Pprod = (unsigned long long)(2 * (W + H[0]));
        unsigned long long P = (unsigned long long)(2 * (W + H[0]));

        vector<unsigned long long> Parr;
        Parr.push_back((unsigned long long)(2 * (W + H[0])));

        deque<pair<long long, long long>> useful;

        useful.push_back(pair<long long, long long>(L[0], H[0]));

        for (int j = 1; j < N; j++)
        {
            long long Li, Hi, Pi;

            if (j >= K)
            {
                Li = ((AL * L[j - 2] + BL * L[j - 1] + CL) % DL) + 1;
                L.push_back(Li);
                Hi = ((AH * H[j - 2] + BH * H[j - 1] + CH) % DH) + 1;
                H.push_back(Hi);
            }
            else
            {
                Li = L[j];
                Hi = H[j];
            }

            if (Li > L[j - 1] + W)
            {
                Pi = 2 * (W + Hi);
                useful.clear();
            }
            else
            {
                Pi = 2 * (Li - L[j - 1]);

                long long h = 0;

                while (!useful.empty() && (useful.front()).first < Li - W)
                    useful.pop_front();

                if (!useful.empty())
                    h = (useful.front()).second;

                if (Hi > h)
                {
                    Pi += 2 * (Hi - h);
                    useful.clear();
                }
                else
                {
                    while (!useful.empty() && (useful.back()).second < Hi)
                        useful.pop_back();
                }
            }

            useful.push_back(pair<unsigned long long, unsigned long long>(Li, Hi));
            unsigned long long newP = ((((unsigned long long)Pi) % modNum) + (((unsigned long long)P) % modNum)) % modNum;
            Parr.push_back(newP);
            Pprod = ((Pprod % modNum) * (newP % modNum)) % modNum;
            P = newP;
        }
        Pprod %= modNum;
        outfile << "Case #" << i + 1 << ": " << Pprod << "\n";

        //printing fun
        // for (unsigned long long x : Parr)
        //     printf("%llu ", x);
        // printf(": %llu", Pprod);
        // printf("\n");
    }
    infile.close();
    outfile.close();

    return 0;
}