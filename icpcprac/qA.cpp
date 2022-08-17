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

dbl calcSlope(vi a, vi b)
{
    if (b[0] == a[0] || b[1] == a[1])
    {
        return 0.0;
    }
    return (dbl)((dbl)(b[1] - a[1]) / (dbl)(b[0] - a[0]));
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    while (cin >> n)
    {
        vector<vi> sus(n);
        for (int i = 0; i < n; ++i)
        {
            vector<int> k(2);
            cin >> k[0] >> k[1];
            sus[i] = k;
        }
        dbl total = 0;
        // vector<dbl> slopes(n, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                // cout << "slope of (" << sus[i][0] << ", " << sus[i][1] << ") and (" << sus[j][0] << ", " << sus[j][1] << ") is " << slop << "\n";
                if (abs(calcSlope(sus[i], sus[j])))
                {
                    total += (2.0 / ((dbl)n * (dbl)n));
                    // ++good;
                    // ++slopes[j];
                }
            }
            // slopes[i] += good;
        }
        // for (int i = 0; i < n; ++i)
        // {
        //     cout << slopes[i] << ", ";
        // }
        // cout << "\n";
        // dbl total = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     total += (1.0 / (dbl)n) * (slopes[i] / (dbl)n);
        // }
        cout << total << "\n";
    }
    return 0;
}