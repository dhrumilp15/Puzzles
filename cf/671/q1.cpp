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
    for (int tt = 0; tt < t; ++tt)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            int dig;
            cin >> dig;
            if (dig % 2)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
            continue;
        }
        string digits;
        cin >> digits;
        int rodds = 0, bevens = 0, revens = 0, bodds = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2)
            {
                rodds += (digits[i - 1] - '0') % 2;
                revens += (digits[i - 1] - '0') % 2 == 0;
            }
            else
            {
                bevens += (digits[i - 1] - '0') % 2 == 0;
                bodds += (digits[i - 1] - '0') % 2;
            }
        }
        // cout << "for " << digits << ": " << bodds << " " << revens << endl;

        if (bodds >= revens)
        {
            rodds -= (bodds - revens);
        }
        else
        {
            bevens -= (revens - bodds);
        }
        // Now both r and b have only their respective parity
        // cout << "for " << digits << ": " << bevens << " " << rodds << endl;

        if (bevens >= rodds)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}