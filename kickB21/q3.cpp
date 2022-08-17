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

pii binsearch(int left, int right, int sqrtbigg, vector<long long> primes) {
    if (left <= right) {
        int mid = (left + right) / 2;
        
        if (mid == 0 || mid == primes.size() - 1) {
            return make_pair(primes[mid], mid);
        }
        
        if (primes[mid] == sqrtbigg) {
            return make_pair(primes[mid-1], mid - 1);
        }

        if (primes[mid] < sqrtbigg && primes[mid + 1] > sqrtbigg) {
            return make_pair(primes[mid], mid);
        }

        if (sqrtbigg < primes[mid]) {
            return binsearch(left, mid - 1, sqrtbigg, primes);
        } else {
            return binsearch(mid + 1, right, sqrtbigg, primes);
        }
    }
    return make_pair(0,0);
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vll nums(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    ll bigg = *(max_element(nums.begin(), nums.end()));
    ll sqrtbigg = sqrt(bigg);
    ll sqsqbigg = sqrt(sqrtbigg); // bigg ^ (1/4) - 
    
    vector<bool> sieve((sqsqbigg + 1) * (sqrtbigg + 1) / 2, true);
    vll primes;

    // n ^ 1/4 * (n ^ 1/2) / 2
    for (int i = 1;i <= sqsqbigg / 2; ++i) {
        for (int j = 2 * i * (i + 1); j <= sqrtbigg / 2; j += 2*i + 1) {
            sieve[j] = false;
        }
    }
    int amount = 1;
    primes.push_back(2);

    for (int i = 1; i <= sqrtbigg / 2; ++i) {
        if (sieve[i]) {
            primes.push_back(2 * i + 1);
            amount++;
        }
    }

    for (ll i : primes) {
        cout << i << ", ";
    }
    cout << "\n";

    for (int i = 0; i < n; ++i) {
        pii value = binsearch(0, amount, sqrt(nums[i]), primes);
        if (nums[i] % value.first == 0) {
            cout << "Case #" << i + 1 << ": " << nums[i] << "\n";
        } else {
            ll smallr = value.first * primes[value.second - 1];
            ll biggr = value.first * primes[value.second + 1];
            
            if (biggr < nums[i]) {
                cout << "Case #" << i << ": " << biggr << "\n";
            } else {
                cout << "Case #" << i << ": " << smallr << "\n";
            }
        }
    }
    
    return 0;
}
