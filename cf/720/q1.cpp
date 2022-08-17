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
        ll A, B;
        cin >> A >> B;
        if (B == 1)
        {
            cout << "NO"
                 << "\n";
            continue;
        }
        else
        {
            cout << "YES"
                 << "\n";
            cout << A << " " << A * B << " " << A + A * B << "\n";
        }
    }
    return 0;
}