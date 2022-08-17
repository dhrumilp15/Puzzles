#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
#define endl "\n";
#define f first;
#define s second;

string dec2bin(int num)
{
    stack<int> bits;
    while (num)
    {
        bits.push(num & 1);
        num >>= 1;
    }
    string bin;
    while (!bits.empty())
    {
        bin += bits.top() + '0';
        bits.pop();
    }
    return bin;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int dec;
        cin >> dec;
        string binrep = dec2bin(dec);
    }
    return 0;
}