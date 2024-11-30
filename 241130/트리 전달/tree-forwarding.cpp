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
            dp[nxt] = dp[cur] + cost[nxt];
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
        parent[i] = num; //-1 1 2 3 4 
        if (num != -1)
        {
            adj[num].push_back(i);         
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int node, value;
        cin >> node >> value;

        cost[node] = value;
    }

    
    vis[1] = 1;
    DFS(1);

    for (int i = 1; i <= n; ++i)
    {
        cout << dp[i] << " ";
    }
    return 0;
}