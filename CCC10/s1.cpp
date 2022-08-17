#include <bits/stdc++.h>

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
    int n;
    cin >> n;
    vector<pair<int, string>> total(n, make_pair(0, ""));
    for (int i = 0; i < n; ++i)
    {
        string k;
        cin >> k;
        vi arr(3, 0);
        for (int j = 0; j < 3; ++j)
        {
            cin >> arr[j];
        }
        total[i] = make_pair(2 * arr[0] + 3 * arr[1] + arr[2], k);
    }
    sort(total.begin(), total.end(), [](const auto &a, const auto &b) {
        if (a.first == b.first)
        {
            return lexicographical_compare(a.second.begin(), a.second.end(), b.second.begin(), b.second.end());
        }
        else
        {

            return a.first > b.first;
        }
    });
    // for (auto i : total)
    // {
    //     cout << i.first << i.second << ", ";
    // }
    // cout << endl;
    if (n >= 2)
    {
        cout << total[0].second << endl;
        cout << total[1].second;
    }
    else if (n > 0)
    {
        cout << total[0].second;
    }
    cout << endl;

    return 0;
}