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
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t)
    {
        int big_max = INT_MIN;
        for (int i = 0; i < 3; ++i)
        {
            int fi;
            cin >> fi;
            big_max = max(fi, big_max);
        }
        cout << big_max << endl;
    }
    return 0;
}