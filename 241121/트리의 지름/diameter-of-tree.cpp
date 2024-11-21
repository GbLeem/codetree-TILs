#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<pair<int, int>> adj[100002];
int vis[100002];
int dist[100002];

int n;

void DFS(int cur, int total_dist)
{
    for(auto nxt : adj[cur])
    {
        int v, l;
        v = nxt.first;
        l = nxt.second;

        if(!vis[v])
        {
            vis[v] = 1;
            dist[cur] = total_dist + l;
            DFS(v, total_dist + l);
        }
    }
}

pair<int, int> FindLargestVertex(int cur)
{
    //초기화
    for(int i = 0; i < n; ++i)
    {
        vis[i + 1] = 0;
        dist[i + 1] = 0;
    }

    vis[cur] = 1;
    dist[cur] = 0;
    DFS(cur, 0);

    int far_dist = -1;
    int far_vertex = -1;

    for(int i = 0; i < n;++i)
    {
        if(dist[i] > far_dist)
        {
            far_dist = dist[i];
            far_vertex = i + 1;
        }
    }

    return make_pair(far_vertex, far_dist);
}

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int u, v, l;
        cin >> u >> v >> l;

        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }

    int far_vertex;
    tie(far_vertex, ignore) = FindLargestVertex(1);

    int answer;
    tie(ignore, answer) = FindLargestVertex(far_vertex);

    cout << answer;

    return 0;
}