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
    for (int i = 1; i <= T; ++i)
    {
        int n, k;
        cin >> n >> k;
        string word;
        cin >> word;
        for (int j = 0; j < (int)(word.length()) / 2; ++j)
        {
            if (word[j] != word[n - j - 1])
            {
                k--;
            }
        }
        cout << "Case #" << i << ": " << abs(k) << "\n";
    }
    return 0;
}