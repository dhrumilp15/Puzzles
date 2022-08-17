#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<long double> vld;
#define endl "\n";
#define f first;
#define s second;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt)
    {
        vector<vll> G(3, vll(3));
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (j == 1 && i == 1)
                    continue;
                cin >> G[i][j];
            }
        }
        // for (int i = 0; i < 3; ++i)
        // {
        //     for (int j = 0; j < 3; ++j)
        //     {
        //         cout << G[i][j] << ", ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        int baseprogs = 0;
        if ((G[0][1] * 2) == (G[0][0] + G[0][2]))
        {
            ++baseprogs;
        }
        if ((G[2][1] * 2) == (G[2][0] + G[2][2]))
        {
            ++baseprogs;
        }
        if ((G[1][0] * 2) == (G[0][0] + G[2][0]))
        {
            ++baseprogs;
        }
        if ((G[1][2] * 2) == (G[0][2] + G[2][2]))
        {
            ++baseprogs;
        }
        unordered_map<ll, ll> prog;
        // cout << "Baseprogs: " << baseprogs << "\n";
        // cout << "desired nums: " << G[0][0] + G[2][2] << ", " << G[0][1] + G[2][1] << ", " << G[0][2] + G[2][0] << ", " << G[1][0] + G[1][2] << "\n ";
        vll res = {
            G[0][0] + G[2][2],
            G[0][1] + G[2][1],
            G[0][2] + G[2][0],
            G[1][0] + G[1][2]};
        for (int val : res)
        {
            if (val % 2 == 0)
            {
                prog[val]++;
            }
        }
        ll value = 0;
        for (auto &it : prog)
        {
            // cout << it.first << ", " << it.second << "\n";
            value = max(value, it.second);
        }
        cout << "Case #" << tt << ": " << value + baseprogs << "\n";
    }
    return 0;
}