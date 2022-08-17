#include <bits/stdc++.h>

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
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int n, k;
        cin >> n >> k;
        ll base = k / n;
        if (base == 0)
        {
            if (n % k == 0)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 2 << "\n";
            }
        }
        else
        {
            if (k % n != 0)
                base += 1;
            cout << base << "\n";
        }
    }
    return 0;
}