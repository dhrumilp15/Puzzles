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
    int N, D;
    cin >> N >> D;
    vi trains;
    for (int i = 0; i < N; ++i)
    {
        int k;
        cin >> k;
        trains.push_back(k);
    }
    vi ptrains;
    int prev = 0;
    for (int i = 0; i < N; ++i)
    {
        ptrains.push_back(prev + trains[i]);
        prev += trains[i];
    }
    int first = 0;
    int last = N;

    for (int i = 0; i < D; ++i)
    {
        int k;
        cin >> k;
        int Fsum = ptrains[first + k - 1];

        if (first != 0)
            Fsum -= ptrains[first - 1];
        int Ssum = ptrains[last - 1] - ptrains[first + k - 1];
        if (Fsum >= Ssum)
        {
            cout << Fsum << endl;
            first += k;
        }
        else
        {
            cout << Ssum << endl;
            last = first + k;
        }
    }
    return 0;
}