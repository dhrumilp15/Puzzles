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

struct lessthan
{
    bool operator()(const pii &a, const pii &b) const
    {
        return a.first < b.first;
    }
};

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int N;
        cin >> N;
        vector<pair<int, int>> pts;
        vector<int> x;
        vector<int> y;
        for (int j = 0; j < N; ++j)
        {
            int x1, y1;
            cin >> x1 >> y1;
            x.push_back(x1);
            y.push_back(y1);
            pts.push_back(make_pair(x1, y1));
        }
        set<pair<int, int>> nt;

        nth_element(y.begin(), y.begin() + N / 2, y.end());
        nth_element(x.begin(), x.begin() + N / 2, x.end());
        sort(pts.begin(), pts.end(), lessthan());

        int medy = y[N / 2];
        int medx = x[N / 2];

        for (int j = 0; j < N; ++i)
        {
            if (pts[i].second == medy)
            {
                nt.insert(pts[i]);
            }
        }

        cout << "Case #" << i + 1 << ": " << total << "\n";
    }
    return 0;
}