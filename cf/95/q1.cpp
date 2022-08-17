#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
#define endl "\n";
#define f first;
#define s second;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int te = 0; te < t; ++te)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        ll trades = ((y + 1) * k  - 1) / (x - 1) + k;

        if ((trades - k) * (x - 1) == (y + 1) * k - 1)
        {
            cout << trades << endl;
        }
        else
        {
            cout << trades + 1 << endl;
        }
    }
    return 0;
}