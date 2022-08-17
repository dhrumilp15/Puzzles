#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl "\n";
#define f first;
#define s second;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt)
    {
        int n, m;
        cin >> n >> m;
        vector<vi> matrix(n, vi(m, 0));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> matrix[i][j];
            }
        }
        ll total = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                ll here = matrix[i][j];
                ll hoval = 0;
                ll bval = 0;
                ll boval = 0;
                double count = 1.0;
                if (n - i - 1 != i && m - j - 1 != j)
                {
                    bval = matrix[n - i - 1][j];
                    boval = matrix[n - i - 1][m - j - 1];
                    hoval = matrix[i][m - j - 1];
                    count = 4.0;
                }
                else if (n - i - 1 != i)
                { // m - j - 1 == j
                    bval = matrix[n - i - 1][j];
                    count = 2.0;
                }
                else if (m - j - 1 != j)
                { // n - i - 1 == i
                    hoval = matrix[i][m - j - 1];
                    count = 2.0;
                }

                ll sum = here + bval + hoval + boval;
                ll avg = round(sum / count);

                if (n - i - 1 != i && m - j - 1 != j)
                {
                    total += abs(bval - avg);
                    total += abs(boval - avg);
                    total += abs(hoval - avg);
                }
                else if (n - i - 1 != i)
                { // m - j - 1 == j
                    total += abs(bval - avg);
                }
                else if (m - j - 1 != j)
                { // n - i - 1 == i
                    total += abs(hoval - avg);
                }
                total += abs(here - avg);

                matrix[i][j] = avg;
                matrix[n - i - 1][j] = avg;
                matrix[i][m - j - 1] = avg;
                matrix[n - i - 1][m - j - 1] = avg;
            }
        }
        cout << total << endl;
    }
    return 0;
}