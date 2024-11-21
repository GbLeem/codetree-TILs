#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int m;
vector<int> adj[1002];
int vis[1002];

unordered_map<int, int> cycle;
set<int> s;
set<int> temp;
int root;
bool bCycle = false;

void DFS(int cur)
{
    vis[cur] = 1;
    temp.insert(cur);

    for (int nxt : adj[cur])
    {
        if (!vis[nxt])
        {
            vis[nxt] = 1;
            temp.insert(nxt);
            DFS(nxt);
        }
    }
}

int main()
{
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        cycle[b]++;
        s.insert(a);
        s.insert(b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //순환구조
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        if (cycle[*it] == 0)
            root = *it;
        if (cycle[*it] >= 2)
            bCycle = true;
    }

    DFS(root);

    //사이클 없고 모든 노드 다 방문하면
    if (!bCycle && temp.size() == s.size())
        cout << 1;

    else
        cout << 0;

    return 0;
}