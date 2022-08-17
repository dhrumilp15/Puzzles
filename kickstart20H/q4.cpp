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

int bfs(unordered_map<int, unordered_set<int>> graph, int start, int target)
{
    queue<pii> q;
    q.push(make_pair(start, 0));
    unordered_set<int> v;
    while (!q.empty())
    {
        pii current = q.front();
        q.pop();
        if (current.first == target)
        {
            return current.second;
        }
        if (v.find(current.first) == v.end())
        {
            for (auto it : graph.find(current.first)->second)
            {
                q.emplace(make_pair(it, current.second + 1));
            }
            v.insert(current.first);
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int T;
    for (int i = 0; i < T; ++i)
    {
        int N, Q;
        cin >> N >> Q;
        vector<string> people;
        for (int j = 0; j < N; ++j)
        {
            string p;
            cin >> p;
            people.push_back(p);
        }
        //build graph
        unordered_map<char, unordered_set<int>> charmap;
        for (int j = 0; j < people.size(); ++j)
        {
            for (char c : people[j])
            {
                charmap[c].insert(j);
            }
        }
        unordered_map<int, unordered_set<int>> graph;
        for (int j = 0; j < people.size(); ++j)
        {
            for (char c : people[j])
            {
                auto got = charmap.find(c);
                if (got != charmap.end())
                {
                    for (auto it = got->second.begin(); it != got->second.end(); ++it)
                        graph[j].insert(*it);
                }
            }
        }

        for (int j = 0; j < Q; ++j)
        {
            int start, target;
            cin >> start >> target;
            cout << bfs(graph, start, target) << "\n";
        }
    }
    return 0;
}