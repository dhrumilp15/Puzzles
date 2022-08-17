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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int times = (a + b + c) / 7;
        if (times == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            a -= times;
            b -= times;
            c -= times;
            if (a <= 0 || b <= 0 || c <= 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                if (a + b + c == 6)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}