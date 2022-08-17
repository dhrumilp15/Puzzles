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

bool bfs(int start, string belts, int rooms);
vector<int> getNeighbours(int k, int rooms, string belts);

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    for (int k = 0; k < N; ++k)
    {
        int rooms;
        cin >> rooms;
        string belts;
        cin >> belts;

        int final = 0;
        bool cycle = true;
        vector<int> good(rooms, 0);
        for (int i = 0; i < rooms; ++i)
        {
            if ((belts[i] == '>' && belts[(((i - 1) % rooms) + rooms) % rooms] == '<') || (belts[i] == '<' && belts[(((i - 1) % rooms) + rooms) % rooms] == '>'))
            {
                cycle = false;
                good[i] = -1;
            }
            else
            {
                if (belts[i] == '-')
                {
                    good[i] = 1;
                    good[(i + 1) % rooms] = 1;
                }
                if (belts[(((i - 1) % rooms) + rooms) % rooms] == '-')
                {
                    good[i] = 1;
                    good[(((i - 1) % rooms) + rooms) % rooms] = 1;
                }
            }
        } // we still technically don't know if there's a cycle in the graph
        if (!cycle)
        {
            int sum = 0;
            for (int i : good)
            {
                if (i == 1)
                    ++sum;
            }
            cout << sum << endl;
        }
        else
        {
            bool cw = true;
            // test if we can go around the graph clockwise
            for (char &c : belts)
            {
                if (c == '<')
                {
                    cw = false;
                }
            }
            //counter clockwise
            bool ccw = true;
            for (int i = 0; i < rooms; ++i)
            {
                int j = (rooms - i) % rooms;
                if (belts[j] == '>')
                {
                    ccw = false;
                }
            }
            if (cw || ccw)
            {
                cout << rooms << endl;
            }
            else
            {
                int sum = 0;
                for (int i : good)
                {
                    if (i == 1)
                        ++sum;
                }
                cout << sum << endl;
            }
        }
    }
    return 0;
}