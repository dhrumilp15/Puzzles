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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string cells;
        cin >> cells;
        vector<int> count(n);
        for (int i = 0; i < n; ++i)
        {
            count[i] = cells[i] - '0';
        }

        for (int i = 0; i < n; ++i)
        {
            // cout << cells << "\n";
            if (cells[i] == '1')
            {
                for (int j = i - 1; j >= max(0, i - m); --j)
                {
                    if (cells[j] == '1')
                    {
                        break;
                    }
                    if (cells[j] == '0')
                    {
                        count[j]++;
                    }
                }

                for (int j = i + 1; j <= min(n - 1, i + m); ++j)
                {
                    if (cells[j] == '1')
                    {
                        break;
                    }
                    if (cells[j] == '0')
                    {
                        count[j]++;
                    }
                }
            }
        }
        // cout << "\n";
        // for (int i : count)
        // {
        //     cout << i << "";
        // }
        // cout << "\n";
        // cout << "\n";
        for (int i = 0; i < n; ++i)
        {
            if (count[i] == 1 || count[i] == 0)
            {
                cout << count[i];
            }
            else if (count[i] == 2)
            {
                if (count[i - 1] == 1 && count[i + 1] == 1)
                {
                    cout << 0;
                }
                else
                {
                    cout << 1;
                }
            }
            else
            {
                cout << 0;
            }
        }
        cout << "\n";
    }
    return 0;
}