#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define endl "\n";
#define f first;
#define s second;

vector<vll> operator*(const vector<vll> &a, const vector<vll> &b)
{
    vector<vll> ans(a[0].size(), vll(b.size(), 0));
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b[0].size(); ++j)
        {
            for (int k = 0; k < a[0].size(); ++k)
            {
                ans[i][j] += ((a[i][k] % 1000000007) * (b[k][j] % 1000000007)) % 1000000007;
            }
        }
    }
    return ans;
}

vector<vll> mult(vector<vll> &transition, long long N, int T)
{
    vector<vll> ans(T + 1, vll(T + 1, 0));
    for (int i = 0; i < T + 1; ++i)
    {
        ans[i][i] = 1;
    }
    while (N)
    {
        if (N % 2 == 1)
        {
            ans = ans * transition;
        }
        transition = transition * transition;
        N >>= 1;
    }
    return ans;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    ll N, K, T, C;
    cin >> N >> K >> T >> C;
    vector<vll> transition(T + 1, vll(T + 1, 0));
    transition[T][0] = K;
    transition[0][0] = 1;
    for (int i = 0; i < T; ++i)
    {
        transition[i][i + 1] = 1;
    }
    vector<vll> state(1, vll(T + 1, 0));
    state[0][0] = C;
    vector<vll> cumu_transition = mult(transition, N - 1, T);
    vector<vll> ans = state * cumu_transition;

    long long sum = (2 * (ans[0][0] % 1000000007)) % 1000000007;
    for (int i = 1; i < ans[0].size(); ++i)
    {
        sum = ((sum % 1000000007) + ((K % 1000000007) * (ans[0][i] % 1000000007)) % 1000000007) % 1000000007;
    }
    cout << sum << endl;
    return 0;
}