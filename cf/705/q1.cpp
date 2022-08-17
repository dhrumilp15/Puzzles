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
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vi ans;
        if (k == 1)
        {
            cout << 0 << "\n\n";
            continue;
        }

        cout << n - k + k / 2 << "\n";
        for (int j = k + 1; j <= n; ++j)
        {
            cout << j << " ";
        }
        for (int j = (k + 1) / 2; j < k; ++j)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}