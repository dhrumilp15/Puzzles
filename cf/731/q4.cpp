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
        cout << "t: " << t << "\n";
        int n;
        cin >> n;
        vi nums(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        vi y(n, 0);
        int last = nums[0] ^ y[0];
        for (int i = 1; i < n; ++i)
        {
            // cout << "i: " << i << "\n";
            int num = 0;
            int place = 0;
            int cop = nums[i];
            while (last && cop)
            {
                // cout << "last: " << last << ", num: " << num << ", cop: " << cop << "\n";
                if (last & 1)
                {
                    num += ((last & 1) ^ (cop & 1)) << place;
                }
                cop >>= 1;
                last >>= 1;
                ++place;
            }
            // cout << "final num: " << num << ", last: " << last << "\n";
            num += last << place;
            y[i] = num;
            last = nums[i] ^ num;
        }
        for (int i : y)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}