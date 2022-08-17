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
        vector<vi> edit = mat; // sadge copy but it is what it is aight
        bool change = true;
        while (change)
        { // run until convergence
            change = false;
            for (int i = 0; i < R; ++i)
            {
                for (int j = 0; j < C; ++j)
                {
                    if (i - 1 >= 0)
                    {
                        int previ = edit[i - 1][j];
                        edit[i - 1][j] = max(edit[i - 1][j], max(0, edit[i][j] - 1));
                        if (edit[i - 1][j] != previ)
                        {
                            change = true;
                        }
                    }
                    if (i + 1 < R)
                    {
                        int previ = edit[i + 1][j];
                        edit[i + 1][j] = max(edit[i + 1][j], max(0, edit[i][j] - 1));
                        if (edit[i + 1][j] != previ)
                        {
                            change = true;
                        }
                    }
                    if (j - 1 >= 0)
                    {
                        int previ = edit[i][j - 1];
                        edit[i][j - 1] = max(edit[i][j - 1], max(0, edit[i][j] - 1));
                        if (edit[i][j - 1] != previ)
                        {
                            change = true;
                        }
                    }
                    if (j + 1 < C)
                    {
                        int previ = edit[i][j + 1];
                        edit[i][j + 1] = max(edit[i][j + 1], max(0, edit[i][j] - 1));
                        if (edit[i][j + 1] != previ)
                        {
                            change = true;
                        }
                    }
                }
            }
        }
        ll totalsum = 0;
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                ll diff = edit[i][j] - mat[i][j];
                if (diff > 0)
                {
                    totalsum += diff;
                }
            }
        }

        cout << "Case #" << t << ": " << totalsum << "\n";
    }
    return 0;
}