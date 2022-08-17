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
        int n;
        cin >> n;
        vll nums(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        vector<vll> moves;
        ll val = min(nums[0], nums[1]);

        moves.push_back({1, 2, val, 1000000007});
        nums[0] = val;
        nums[1] = 1000000007;

        for (ll i = 3; i < n; i += 2)
        {
            nums[i - 1] = min(nums[i], nums[i - 1]);
            nums[i] = 1000000007;
            moves.push_back({i - 1, i, nums[i - 1], nums[i]});
        }
        cout << moves.size() << "\n";
        for (auto v : moves)
        {
            for (ll i : v)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}