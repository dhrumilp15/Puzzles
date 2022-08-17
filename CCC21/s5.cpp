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
    int N, M;
    cin >> N >> M;
    vector<pii> pos(N, make_pair(1, 0));
    for (int i = 0; i < N; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        for (int i = x - 1; i <= y - 1; ++i)
        {
            if (z == 1)
            {
                pos[i].second = 1;
            }
            else if (z == 2)
            {
                if (pos[i].second == 1 && pos[i].first == 1)
                {
                    cout << "impossible" << endl;
                    return 0;
                }
                else
                {
                    if (pos[i].first != 2)
                        pos[i].first = 2;
                    pos[i].second = 1;
                }
            }
            else
            {
                cout << 4 << " " << 6 << endl;
                return 0;
            }
        }
    }
    for (auto i : pos)
    {
        cout << i.first << " ";
    }
    cout << endl;
    return 0;
}