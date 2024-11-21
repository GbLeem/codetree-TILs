#include <iostream>
#include <vector>
using namespace std;

int n, m;
int parent[55];
vector<int> adj[55];
int vis[55];
int root = 0;
int leaf = 0;

void DFS(int cur)
{
    vis[cur] = 1;
    for (auto nxt : adj[cur])
    {
        if (!vis[nxt] && nxt != parent[cur])
        {
            vis[nxt] = 1;
            DFS(nxt);
            leaf++;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> parent[i];
        if (parent[i] == -1)
            root = i;
    }

    for (int i = 0; i < n; ++i)
    {
        int u = i;
        int v = parent[i];
        if(v!=-1)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    cin >> m;

    DFS(m);
    leaf = 0;

    DFS(root);
    cout << leaf;

    return 0;
}