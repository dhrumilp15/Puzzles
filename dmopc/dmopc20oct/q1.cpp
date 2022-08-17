#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
#define endl "\n";
#define f first;
#define s second;
int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string q;
        cin >> q;
        bool Mflag = false, Cflag = false;
        for (int j = 0; j < q.length(); ++j)
        {
            if (q[j] == 'M')
                Mflag = true;
            if (q[j] == 'C')
                Cflag = true;
        }
        if (Mflag && Cflag)
        {
            cout << "NEGATIVE MARKS" << endl;
        }
        else if (Mflag || Cflag)
        {
            cout << "FAIL" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }
}