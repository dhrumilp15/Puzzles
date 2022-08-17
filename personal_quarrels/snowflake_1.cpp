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
    for (int tt = 0; tt < t; ++tt) {
        int N, x;
        cin >> N >> x;
        vi disk;
        for (int i = 0; i < N; ++i) {
            int k;
            cin >> k;
            disk.push_back(k);
        }
        deque<pair<int, int>> q;
        
        for (int i = 0; i < disk.size(); ++i) {
            while (!q.empty() && i >= q.top()) {
                q.pop();
                q.pop_front();
            }
        }

    }
    return 0;
}