#include <iostream>
#include <vector>
using namespace std;

int n, m;
int parent[100'002];
int cost[100'002];
int vis[100'002];
vector<int> adj[100'002];
int dp[100'002];


void DFS(int cur)
{
    for (int nxt : adj[cur])
    {
        if (!vis[nxt])
        {
            vis[nxt] = 1;
            dp[nxt] += dp[cur];
            DFS(nxt);
        }
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        int num;
        cin >> num;
        
        if (num != -1)
        {
            adj[num].push_back(i);         
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int node, value;
        cin >> node >> value;

        dp[node] += value;
    }

        
    DFS(1);

    for (int i = 1; i <= n; ++i)
    {
        cout << dp[i] << " ";
    }
    return 0;
}