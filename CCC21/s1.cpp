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
    int n;
    cin >> n;
    vector<double> heights(n + 1);
    vector<double> widths(n);
    for (int i = 0; i < n + 1; ++i)
    {
        cin >> heights[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> widths[i];
    }
    double total = 0.0;

    for (int i = 0; i < n; ++i)
    {
        total += (widths[i] * (heights[i] + heights[i + 1])) / 2.0;
    }
    if (abs(abs(total - (int)total) - 0.5) <= 0.1)
    {
        total = (int)total + 0.5;
    }
    cout << total << endl;

    return 0;
}