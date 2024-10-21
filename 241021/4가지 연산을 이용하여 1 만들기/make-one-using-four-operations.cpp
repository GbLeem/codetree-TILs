#include <iostream>
#include <queue>
using namespace std;

int n;
int vis[1'000'002]; //dist

int main() 
{
    cin >> n;

    fill(vis + 1, vis + 1'000'002, -1);

    //1부터 시작해서 올라가기
    queue<int> q;
    q.push(1);
    vis[1] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int nxt : {cur -1, cur + 1, cur * 2, cur * 3})
        {
            if(nxt < 0 || nxt > 100000)
                continue;
            if(vis[nxt] != -1)
                continue;
            q.push(nxt);
            vis[nxt] = vis[cur] + 1;
        }
    }

    cout << vis[n];
    return 0;
}