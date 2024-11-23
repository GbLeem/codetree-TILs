#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n;
int answer = 0;
vector<int> adj[100002];
int vis[100002];
int dist[100002];
unordered_map<int, int> um;

void DFS(int cur)
{
    for(int nxt : adj[cur])
    {
        if(!vis[nxt])
        {
            vis[nxt] = 1;
            dist[nxt] = dist[cur] + 1;
            DFS(nxt);
        }
    }
}

int main() 
{
    cin >> n;
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        um[u]++;
        um[v]++;        
    }

    DFS(1);

    for(int i = 1; i<= n; ++i)
    {
        if(um[i] == 1 && i != 1)
        {
            answer += dist[i];
        }
    }
    if(answer % 2 == 0)
        cout << 0;
    else
        cout << 1;
    return 0;
}