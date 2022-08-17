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
    int n;
    while (cin >> n)
    {
        vector<vi> pairs(n, vi(n));

        for (int i = 0; i < n; ++i)
        {
            vector<int> a;
            cin >> a[0] >> a[0];
            pairs[i] = a;
        }
        sort(pairs.begin(), pairs.end());
        vector<vi> grid(n, vi(n));
        for (int i = 0; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            grid[x][y] = 1;
        }
        if (n < 4)
            cout << 0 << "\n";
        int bigshaq = 0;

        vector<vi> dp(n + 1, vi(n + 1));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (grid[i - 1][j - 1] != 0)
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    bigshaq = max(bigshaq, dp[i][j]);
                }
            }
        }
        cout << bigshaq << "\n";
    }
    return 0;
}