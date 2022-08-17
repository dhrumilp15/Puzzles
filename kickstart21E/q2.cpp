#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
#define endl "\n";
#define f first;
#define s second;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int cases;
    cin >> cases;
    for (int tt = 1; tt <= cases; ++tt)
    {
        int R, C, K;
        cin >> R >> C >> K;
        vector<vector<int>> cake(R, vector<int>(C));
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int rowcut = (r2 - r1) / K;
        if ((r2 - r1) % K) {
            ++rowcut;
        }
        int colcut = (c2 - c1) / K;
        if ((c2 - c1) % K) {
            ++colcut;
        }
        int p1pathH = 0;
        int p2pathH = 0;
        int p3pathH = 0;
        int p4pathH = 0;

        int p1pathV = 0;
        int p2pathV = 0;
        int p3pathV = 0;
        int p4pathV = 0;
        // c1path
        if (r1 != 0) {
            p1pathH += c2 + 1;
            p2pathH += C - (c1 - 1) + 1;
            p3pathH += c2 - (c1 - 1) + 1;
            p4pathH += c2 - (c1 - 1) + 1;
            p1pathV += c2 - (c1 - 1);
            p2pathV += c2 - (c1 - 1);
            p3pathV += c2 - (c1 - 1) + 1;s
        }
        if (c2 != C) {
            p1pathH += r2 - (r1 - 1) + 1;
            p2pathH += r2 - (r1 - 1) + 1;
            p3pathH += r2 - (r1 - 1);
            p4pathH += r2 - (r1 - 1) + 1;
            p1pathV += r2 - (r1 - 1) + 1;
            p2pathV += r2 + 1;
        }
        if (r2 != R) {
            p1pathH += c2 - (c1 - 1) + 1;
            p2pathH += c2 - (c1 - 1);
            p3pathH += C - (c1 - 1) + 1;
            p4pathH += c2 + 1;
            p1pathV += c2 - (c1 - 1) + 1;
            p2pathV += c2 - (c1 - 1) + 1;
            p3pathV += C - (c1 - 1);
        }
        if (c1 != 0) {
            p1pathH += r2 - (r1 - 1);
            p2pathH += r2 - (r1 - 1) + 1;
            p3pathH += r2 - (r1 - 1) + 1;
            p4pathH += r2 - (r1 - 1);
            p1pathV += r2 + 1;
            p2pathV += r2 - (r1 - 1) + 1;
            p3pathV += r2 - (r1 - 1) + 1;
        }

        int c1path = (c2 + 1) + (r2 - (r1 - 1) + 1) + (c2 - (c1 - 1) + 1) + (r2 - (r1 - 1));
        int c2path = C - (c1 - 1) + r2 - r1 + 1 +  1 + c2 - c1 + 1 + r2 - r1;
        int c1path = c2 + 1 + r2 - r1 + 1 + c2 - c1 + 1 + r2 - r1;
        int c1path = c2 + 1 + r2 - r1 + 1 + c2 - c1 + 1 + r2 - r1;


    }
    return 0;
}