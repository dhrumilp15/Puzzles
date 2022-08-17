#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define endl "\n";
#define f first;
#define s second;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int R, C;
        cin >> R >> C;
        vector<vi> mat(R, vi(C, 0));
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                cin >> mat[i][j];
            }
        }

        vector<vector<vi>> dp(R, vector<vi>(C, vi(4)));
        // left, right, up, down
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (mat[i][j])
                {
                    if (j - 1 >= 0)
                    {
                        dp[i][j][0] = dp[i][j - 1][0] + 1;
                    }
                    else
                    {
                        dp[i][j][0]++;
                    }
                }
            }
        }

        for (int i = 0; i < R; ++i)
        {
            for (int j = C - 1; j >= 0; --j)
            {
                if (mat[i][j])
                {
                    if (j + 1 < C)
                    {
                        dp[i][j][1] = dp[i][j + 1][1] + 1;
                    }
                    else
                    {
                        dp[i][j][1]++;
                    }
                }
            }
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (mat[i][j])
                {
                    if (i - 1 >= 0)
                    {
                        dp[i][j][2] = dp[i - 1][j][2] + 1;
                    }
                    else
                    {
                        dp[i][j][2]++;
                    }
                }
            }
        }

        for (int i = R - 1; i >= 0; --i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (mat[i][j])
                {
                    if (i + 1 < R)
                    {
                        dp[i][j][3] = dp[i + 1][j][3] + 1;
                    }
                    else
                    {
                        dp[i][j][3]++;
                    }
                }
            }
        }

        // cout << "people\n";
        // for (int i = 0; i < R; ++i)
        // {
        //     for (int j = 0; j < C; ++j)
        //     {
        //         cout << "[" << dp[i][j][0] << ", " << dp[i][j][1] << ", " << dp[i][j][2] << ", " << dp[i][j][3] << "]";
        //     }
        //     cout << "\n";
        // }
        int totalsum = 0;

        // (5,0) -> 2
        // (2,0) -> 3

        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                // watch for 0 == 2 * 0
                // left right up down
                // cout << "At "
                //      << "(" << i << ", " << j << "):"
                //      << "\n";
                // cout << "[" << dp[i][j][0] << ", " << dp[i][j][1] << ", " << dp[i][j][2] << ", " << dp[i][j][3] << "]\n";
                int lu = min(dp[i][j][0] / 2, dp[i][j][2]) + min(dp[i][j][0], dp[i][j][2] / 2) - 2;
                int ru = min(dp[i][j][1] / 2, dp[i][j][2]) + min(dp[i][j][1], dp[i][j][2] / 2) - 2;
                int ld = min(dp[i][j][0] / 2, dp[i][j][3]) + min(dp[i][j][0], dp[i][j][3] / 2) - 2;
                int rd = min(dp[i][j][1] / 2, dp[i][j][3]) + min(dp[i][j][1], dp[i][j][3] / 2) - 2;
                if (dp[i][j][0] <= 1)
                {
                    lu = 0;
                    ld = 0;
                }
                if (dp[i][j][1] <= 1)
                {
                    ru = 0;
                    rd = 0;
                }
                if (dp[i][j][2] <= 1)
                {
                    lu = 0;
                    ru = 0;
                }
                if (dp[i][j][3] <= 1)
                {
                    ld = 0;
                    rd = 0;
                }
                // cout << "lu: " << lu << " "
                //      << "ru: " << ru << " "
                //      << "ld: " << ld << " "
                //      << "rd: " << rd << "\n";
                totalsum += lu + ru + ld + rd;
            }
        }

        cout << "Case #" << t << ": " << totalsum << "\n";
    }
    return 0;
}