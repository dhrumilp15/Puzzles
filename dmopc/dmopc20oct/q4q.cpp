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
    ll N, K, T, C;
    cin >> N >> K >> T >> C;
    queue<ll> bebes;
    while (N > 1)
    {
        if (bebes.size() == T)
        {
            bebes.push(C * K);
            C += bebes.front();
            bebes.pop();
        }
        else
        {
            bebes.push(C * K);
        }
        --N;
    }
    ll sum = (2 * (C % 1000000007)) % 1000000007;
    cout << C << " and bebes: ";
    while (!bebes.empty())
    {
        cout << bebes.front() / K << ", ";
        sum = (sum % 1000000007 + bebes.front() % 1000000007) % 1000000007;
        bebes.pop();
    }
    cout << endl;
    cout << sum % (1000000007) << endl;
    return 0;
}