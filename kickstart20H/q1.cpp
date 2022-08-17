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
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, K, S;
        cin >> N >> K >> S;
        cout << "Case #" << i + 1 << ": " << min(N, K - S + N - S) + K << "\n";
    }
    return 0;
}