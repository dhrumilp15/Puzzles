#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
#define endl "\n";
#define f first;
#define s second;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        int n;
        cin >> n;
        vector<int> AB;
        for (int i = 0; i < n; ++i)
        {
            int p;
            cin >> p;
            AB.push_back(p);
        }
        sort(AB.begin(), AB.end());
        cout << "AB: ";
        for (int i : AB)
        {
            cout << i << " ";
        }
        cout << endl;
        vector<int> A;
        vector<int> B;
        int sharedmex = 0;
        int Aptr = 0, Bptr = 1;

        while (Aptr < n)
        {
            if (AB.at(Aptr) == AB.at(Bptr))
            {
                A.push_back(AB.at(Aptr));
                B.push_back(AB.at(Bptr));
                Aptr = Bptr;
                Bptr++;
            }
            else
            {
                A.push_back(AB.at(i));
                A.push_back(AB.at(i + 1));
            }
        }
        if (n % 2 != 0)
        {
            A.push_back(AB.at(n - 1));
        }
        int amex = 0;
        for (int i : A)
        {
            if (i == amex)
            {
                amex++;
            }
        }
        int bmex = 0;
        for (int i : B)
        {
            if (i == bmex)
            {
                bmex++;
            }
        }
        cout << amex + bmex << endl;
        cout << "Amex: " << amex << " A: ";
        for (auto i : A)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "Bmex: " << bmex << " B: ";
        for (auto i : B)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}