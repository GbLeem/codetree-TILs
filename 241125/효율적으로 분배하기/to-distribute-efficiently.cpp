#include <iostream>
#include <queue>
using namespace std;

int n;
int vis[5002];
//5와 3으로 

int main() 
{
    cin >> n;

    fill(vis, vis + 5000, -1);

    vis[n] = 0;
    queue<int> q;
    q.push(n);

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(int nxt : {cur - 5, cur - 3})
        {
            if(vis[nxt] == -1)
            {                
                vis[nxt] = vis[cur] + 1;
                q.push(nxt);
            }
        }   
    }
    
    cout << vis[0];

    return 0;
}