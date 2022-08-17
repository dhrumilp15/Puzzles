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

bool isprime(int n, set<int> memo)
{
    for (auto it = memo.begin(); it->second != memo.end() &&; ++it)
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    set<int> memo;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        if (k & 1 == 1)
        {
            cout << k << " " << k << endl;
            continue;
        }
    }
    return 0;
}