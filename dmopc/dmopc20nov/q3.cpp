#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define endl "\n";
#define f first;
#define s second;

struct node
{
    ll value;
    vi parent;
    vi child;
    ll parents = -1;
    ll children = -1;
};

int countkids(vector<node> &graph, int index)
{
    if (graph[index].children >= 0)
    {
        return graph[index].value + graph[index].children;
    }
    int allkids = 0;
    for (int i : graph[index].child)
    {
        allkids += countkids(graph, i);
    }
    if (graph[index].children == -1)
    {
        graph[index].children = allkids;
    }
    else
    {
        graph[index].children += allkids;
    }

    return graph[index].value + allkids;
}

int countParents(vector<node> &graph, int index)
{
    if (graph[index].parents >= 0)
    {
        return graph[index].value + graph[index].parents;
    }

    int allparents = 0;
    for (int pt : graph[index].parent)
    {
        allparents += countParents(graph, pt);
    }
    if (graph[index].parents == -1)
    {
        graph[index].parents = allparents;
    }
    else
    {
        graph[index].parents += allparents;
    }
    return graph[index].value + allparents;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    auto graph = vector<node>(n + 1, node());
    for (int i = 1; i < n + 1; ++i)
    {
        int k;
        cin >> k;
        graph[i].value = k;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int start, stop;
        cin >> start >> stop;
        graph[start].child.push_back(stop);
        graph[stop].parent.push_back(start);
    }

    for (int i = 1; i < n + 1; ++i)
    {
        countkids(graph, i);
        countParents(graph, i);
    }
    ll connections = 0;
    ll maxdiff = LONG_MIN;
    // auto v = unordered_set<pii>({});

    for (node city : graph)
    {
        connections += city.value * (city.value - 1 + city.children);

        for (int c : city.child)
        {
            maxdiff = max(maxdiff, (city.value + abs(city.children - (graph[c].children + graph[c].value))) * (graph[c].value + abs(graph[c].parents - (city.parents + city.value))));
        }
        for (int p : city.parent)
        {
            maxdiff = max(maxdiff, (graph[p].value + abs(graph[p].children - (city.children + city.value))) * (city.value + abs(city.parents - (graph[p].parents + graph[p].value))));
        }
    }

    // for (node i : graph)
    // {
    //     cout << "value: " << i.value;
    //     cout << "\nchilds: ";
    //     for (int c : i.child)
    //     {
    //         cout << c << ", ";
    //     }
    //     cout << "\nparent: ";
    //     for (int c : i.parent)
    //     {
    //         cout << c << ", ";
    //     }
    //     cout << "\n";
    //     cout << "children: " << i.children;
    //     cout << "\nparents: " << i.parents;
    //     cout << "\n===\n";
    // }
    // cout << "connections: " << connections << " dif: " << maxdiff << " con + dif: ";
    cout << connections + maxdiff;

    return 0;
}