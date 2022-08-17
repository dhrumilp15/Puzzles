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
    int t;
    cin >> t;
    while (t--)
    {
        int xA, yA, xB, yB, xF, yF;
        cin >> xA >> yA >> xB >> yB >> xF >> yF;
        // cout << "A: (" << xA << ", " << yA << "), B: (" << xB << ", " << yB << "), F: (" << xF << ", " << yF << ")\n";

        if (xA != xB && yA != yB)
        {
            cout << abs(xB - xA) + abs(yB - yA) << "\n";
        }
        else
        {
            if (xA == xB && xF == xA && ((yF < yB && yF > yA) || (yF > yB && yF < yA)))
            {
                cout << abs(xB - xA) + abs(yB - yA) + 2 << "\n";
            }
            else if (yA == yB && yF == yA && ((xF < xB && xF > xA) || (xF > xB && xF < xA)))
            {
                cout << abs(xB - xA) + abs(yB - yA) + 2 << "\n";
            }
            else
            {
                cout << abs(xB - xA) + abs(yB - yA) << "\n";
            }
        }
    }
    return 0;
}