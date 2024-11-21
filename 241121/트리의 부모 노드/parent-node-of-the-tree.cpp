#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100002];
int vis[100002];
int parent[100002];

int n;

void DFS(int cur)
{
    vis[cur] = 1;

    for(auto nxt : adj[cur])
    {
        if(!vis[nxt])
        {
            vis[nxt] = 1;
            parent[nxt] = cur;

            DFS(nxt);
        }
    }
}

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);      
    }    

    DFS(1);

    for(int i = 2; i <= n; ++i)
    {
        cout << parent[i]<<"\n";
    }
    return 0;
}