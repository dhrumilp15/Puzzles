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
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; ++t)
    {
        int n;
        cin >> n;
        string word;
        cin >> word;
        char currgroup;
        for (char letter : word)
        {
            if (letter != 'F')
            {
                currgroup = letter;
                break;
            }
        }
        int res = 0;
        for (char letter : word)
        {
            if (letter != 'F')
            {
                if (letter != currgroup)
                {
                    res += 1;
                    currgroup = letter;
                }
            }
        }
        cout << "Case #" << t << ": " << res << "\n";
    }
    return 0;
}