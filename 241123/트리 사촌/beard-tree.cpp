#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> adj[1'000'002];
int node[1'000'002];
int parentIdx = -1;
int lastnum = 0;
int answer = 0;

int vis[1'000'002];
int dist[1'000'002];

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
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        node[i] = num;

        if (i == 0)
        {
            lastnum = num;
        }
        //연속되지 않은 경우 - 부모가 바뀜
        else if (num - lastnum > 1)
        {
            parentIdx++;                                  
            adj[node[parentIdx]].push_back(num);
            lastnum = num;
        }
        else if (num - lastnum == 1)
        {            
            adj[node[parentIdx]].push_back(num);
            lastnum = num;
        }
    }

    DFS(node[0]);

    int temp = 0;
    for(int i = 1; i < n; ++i)
    {
        if(dist[k] == dist[node[i]])
            temp++;
    }

    int p = 0;
    for(int i = 0; i < n; ++i)
    {        
        for(int j = 0; j < adj[node[i]].size(); ++j)
        {
            if(adj[node[i]][j] == k)
            {
                p = node[i];
            }
        }
    }     

    cout << temp - adj[p].size();
    return 0;
}