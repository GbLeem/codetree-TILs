#include <iostream>
using namespace std;

int n, m;
int board[22];
int vis[22];
int answer = 0;

int Check()
{
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        if(vis[i])
            ans ^= board[i];        
    }
    return ans;
}

void Choose(int cur, int cnt)
{
    if(cnt == m)
    {
        answer = max(answer, Check());
        return;
    }
    if(cur == n)
        return;

    Choose(cur + 1, cnt);
    vis[cur] = true;
    Choose(cur + 1, cnt + 1);
    vis[cur] = false;
}

int main() 
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> board[i];
    Choose(0,0);
    cout << answer;
    return 0;
}