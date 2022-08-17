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
    int T;
    cin >> T;
    for (int t = 1; t <= T;++t) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << "Case #" << t << ": " << 2 << '\n';
            continue;
        }
        vll nums;
        for (int i =0; i < n; ++i) {
            cin >> nums[i];
        }
        vll diffs;
        for (int i = 1; i < n; ++i) {
            diffs.push_back(nums[i] - nums[i-1]);
        }
        int group_diff = nums[1] - nums[0];
        int i = 1;
        while (nums[i] - nums[i - 1] == group_diff) {
            
        }

    }
    return 0;
}