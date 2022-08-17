#include <bits/stdc++.h>
#include <fstream>

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
    // this is the dumb cpp solution without the prefix sum array
    int N, D;
    cin >> N >> D;
    vi trains;
    for (int i = 0; i < N; ++i)
    {
        int k;
        cin >> k;
        trains.push_back(k);
    }

    for (int i = 0; i < D; ++i)
    {
        // for (int i : trains)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        int k;
        cin >> k;
        int Fsum = accumulate(trains.begin(), trains.begin() + k, 0);
        int Ssum = accumulate(trains.begin() + k, trains.end(), 0);
        if (Fsum >= Ssum)
        {
            cout << Fsum << endl;
            trains.erase(trains.begin(), trains.begin() + k);
        }
        else
        {
            cout << Ssum << endl;
            trains.erase(trains.begin() + k, trains.end());
        }
    }
    return 0;
}