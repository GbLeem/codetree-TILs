#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<int> adj[100'002];
int answer = INT_MAX;
int dist[100'002];
int vis[100'002];
int maxDist = 0;

void DFS(int cur)
{
    vis[cur] = 1;    
    for (int nxt : adj[cur])
    {
        if (!vis[nxt])
        {
            vis[nxt] = 1;
            dist[nxt] = dist[cur] + 1;
            maxDist = max(maxDist, dist[nxt]);
            DFS(nxt);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //모든 노드로 DFS해서 가장 긴 길이가 짧은 것 구하기
    for (int i = 1; i <= n/2; ++i)
    {
        //초기화
        maxDist = 0;
        for (int j = 1; j <= n; ++j)
        {
            vis[j] = 0;
            dist[j] = 0;
        }

        DFS(i);
        answer = min(answer, maxDist);
    }
    cout << answer;
    return 0;
}