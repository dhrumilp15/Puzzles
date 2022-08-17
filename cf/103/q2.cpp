#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define endl "\n";
#define f first;
#define s second;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int n, k;
        cin >> n >> k;
        vector<ll> p;
        ll ps = 0;
        vector<ll> psum;
        for (int j = 0; j < n; ++j)
        {
            ll pnum;
            cin >> pnum;
            p.push_back(pnum);
            ps += pnum;
            psum.push_back(ps);
        }
        ll added = 0;
        for (int i = 1; i < n; ++i)
        {
            ld percentOfSum = (ld)(100.0 * (ld)p[i]) / (ld)(psum[i - 1] + (ld)added);
            if (percentOfSum > k)
            {
                added = ceil(100.0 * (ld)p[i] / (ld)k - psum[i - 1]);
            }
        }

        cout << added << "\n";
    }

    return 0;
}