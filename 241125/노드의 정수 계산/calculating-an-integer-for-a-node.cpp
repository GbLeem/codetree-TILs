#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> adj[100'002];
int cost[100'002];

int vis[100'002];
int parent[100'002];
int dp[100'002];

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
    
    dp[cur] = cost[cur];
    for(int nxt : adj[cur])
    {        
        if(parent[nxt] == cur)
        {
            if(dp[nxt] > 0)
                dp[cur] += dp[nxt];
        }
    }
}


int main() 
{
    cin >> n;
    for(int i = 2; i <= n ; ++i)
    {
        int t, a, p;
        cin >> t >> a >> p; // 양수음수 / 값 / 부모

        adj[i].push_back(p);
        adj[p].push_back(i);
        if(t == 1)        
            cost[i] = a;             
        else
            cost[i] = -a;
    }

    vis[1] = 1;
    DFS(1);

    cout << dp[1];

    return 0;
}