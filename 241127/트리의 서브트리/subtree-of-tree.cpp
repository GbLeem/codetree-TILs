#include <iostream>
#include <vector>
using namespace std;

int n, r, q;
vector<int> adj[100'002];
int dp[100'002];
int vis[100'002];
int parent[100'002];

void DFS(int cur)
{
    for(int nxt : adj[cur])
    {
        if(!vis[nxt])
        {
            vis[nxt] = 1;
            parent[nxt] = cur;
            DFS(nxt);
        }
    }    

    for(int nxt : adj[cur])
    {
        if(parent[nxt] == cur)
        {
            dp[cur] += dp[nxt];
        }
    }    
}

int main() 
{
    cin >> n >> r >> q;

    for(int i = 0; i < n-1; ++i)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);        
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i)
        dp[i] = 1;

    vis[r] = 1;
    DFS(r);

    for(int i = 0; i < q; ++i)
    {
        int query;
        cin >> query;

        cout << dp[query]<<"\n";
    }



    

    return 0;
}