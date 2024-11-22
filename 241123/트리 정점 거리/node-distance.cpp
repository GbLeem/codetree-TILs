#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> adj[1002];
int dist[1002];
int vis[1002];

void DFS(int st, int total_dist)
{
    vis[st] = 1;

    for(auto nxt : adj[st])
    {
        int u = nxt.first;
        int d = nxt.second;

        if(!vis[u])
        {
            vis[u] = 1;
            dist[u] = total_dist + d;
            DFS(u, total_dist + d);
        }
    }
}

int main() 
{
    cin >> n >> m;
    //n개의 정점

    for(int i = 0; i < n- 1; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;

        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    for(int i = 0; i < m; ++i)
    {
        int st, en;
        cin >> st >> en;

        for(int j = 1; j <= n; ++j)
        {
            dist[j] = 0;
            vis[j] = 0;
        }
        DFS(st, 0);
        cout << dist[en]<<"\n";
    }

    return 0;
}