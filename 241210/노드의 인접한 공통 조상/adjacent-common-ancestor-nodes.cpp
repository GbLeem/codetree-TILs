#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> adj[10'002];
int parent[10'002];
int depth[10'002];
int root[10'002];
int vis[10'002];
int realRoot = 0;

void DFS(int cur)
{
    for (int nxt : adj[cur])
    {           
        if (!vis[nxt])
        {
            vis[nxt] = 1;
            depth[nxt] = depth[cur] + 1;
            DFS(nxt);                
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;

        root[b]++;

        parent[b] = a;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (root[i] == 0)
        {
            realRoot = i;
            break;
        }
    }

    int u, v;
    cin >> u >> v;

    vis[realRoot] = 1;
    DFS(realRoot);


    while (parent[u] != parent[v])
    {
        if (depth[u] > depth[v])
        {
            u = parent[u];
        }
        else
        {
            tempV = parent[v];
        }

        if (u == v)
        {
            cout << u;
            return 0;
        }
    }

    cout << parent[v];

    return 0;
}