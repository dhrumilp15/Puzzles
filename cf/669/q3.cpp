#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
#define f first;
#define s second;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> pos(N, -1);
    for (int i = 0; i < N; ++i)
    {
        if (pos[i] == -1)
        {
            for (int j = i + 1; j < N; ++j)
            {
                cout << "? " << i + 1 << " " << j + 1 << endl;
                int imodj;
                cin >> imodj;

                cout << "? " << j + 1 << " " << i + 1 << endl;
                int jmodi;
                cin >> jmodi;

                if (imodj > jmodi)
                {
                    pos[i] = imodj;
                    break;
                }
                else
                {
                    pos[j] = jmodi;
                }
            }
        }
    }
    cout << "! ";
    for (int i : pos)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}