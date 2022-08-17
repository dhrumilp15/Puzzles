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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, W;
        cin >> n >> W;
        vector<pii> nums;
        for (int j = 0; j < n; ++j)
        {
            int k;
            cin >> k;
            nums.push_back(make_pair(k, j));
        }
        sort(nums.begin(), nums.end(), [](const pii &a, const pii &b) {
            return a.first < b.first;
        });
        int sum = 0;
        vi use;

        for (int k = 0; k < nums.size(); ++k)
        {
            sum += nums[k].first;
            if (sum >= W / 2 && sum <= W)
            {
                use.push_back(nums[k].second);
                cout << use.size() << "\n";
                for (int l : use)
                {
                    cout << l + 1 << " ";
                }
                cout << "\n";
                break;
            }
            else if (sum > W)
            {
                cout << -1 << "\n";
                break;
            }
            use.push_back(nums[k].second);
        }
    }
    return 0;
}