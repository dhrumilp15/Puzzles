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
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = abs(x2 - x1) + abs(y2 - y1);
        if (abs(x2 - x1) != 0 && abs(y2 - y1) != 0)
        {
            sum += 2;
        }
        cout << sum << endl;
    }
    return 0;
}