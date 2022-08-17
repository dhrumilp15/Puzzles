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
        vector<int> players(4);
        for (int i = 0; i < 4; ++i)
        {
            cin >> players[i];
        }
        auto maxtop = max_element(players.begin(), players.end());
        int top = *maxtop;
        int topidx = maxtop - players.begin();
        int top2nd = INT_MIN;
        int top2idx = -1;
        for (int i = 0; i < 4; ++i)
        {
            if (players[i] != top && players[i] > top2nd)
            {
                top2nd = players[i];
                top2idx = i;
            }
        }
        if (topidx % 2)
        {
            if (top2idx == topidx - 1)
            {
                cout << "NO\n";
                continue;
            }
        }
        if (topidx % 2 == 0)
        {
            if (top2idx == topidx + 1)
            {
                cout << "NO\n";
                continue;
            }
        }
        cout << "YES\n";
    }

    return 0;
}