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

vll dpbois(int n, int W, vll &weights, vll &values)
{
    vector<long long> sickomode(W + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cout << "i: " << i << ", weights[i - 1]: " << weights[i - 1] << ", values[i - 1]: " << values[i - 1] << "\n";
        for (int cap = W; cap >= 1; --cap)
        {
            cout << "cap: " << cap << ", " << cap - weights[i - 1] << "\n";
            ll valnocap = sickomode[cap];
            ll valyescap = 0;

            if (cap >= weights[i - 1])
            {
                valyescap = values[i - 1] + sickomode[cap - weights[i - 1]];
            }
            sickomode[cap] = max(valnocap, valyescap);
            for (ll i : sickomode)
            {
                cout << i << ", ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return sickomode;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n, W;
    cin >> n >> W;
    vll values(n);
    vll weights(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
        cin >> values[i];
    }
    cout << dpbois(n, W, weights, values)[W] << "\n";

    return 0;
}