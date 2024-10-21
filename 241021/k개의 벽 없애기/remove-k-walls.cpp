#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int n, k;
int board[102][102];
int vis[102][102];
int r1, c1, r2, c2;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int answer = -1;

void BFS(int x, int y)
{
    for(int i = 0 ; i < n; ++i)
        fill(vis[i], vis[i] + n, -1);

    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 0;

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if(board[nx][ny] == 1 || vis[nx][ny] != -1) //벽이거나 방문한 경우
                continue;
            
            q.push({nx, ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }
}

void Check()
{
    //못가는 경우
    if(vis[r2 - 1][c2 - 1] != -1)
    {
        answer = min(answer, vis[r2 - 1][c2 - 1]);
    }    
}

void Choose(int cur)
{
    if(cur == k + 1)
    {
        BFS(r1 - 1, c1 - 1);
        Check();

        return ;
    }

    for(int i = 0; i < n*n; ++i)
    {
        int x = i / n;
        int y = i % n;

        if(board[x][y] == 1) //벽이면
        {
            board[x][y] = 1;
            Choose(cur + 1);
            board[x][y] = 0;
        }
    }
}

int main() 
{
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;

    Choose(1);

    if(answer != -1)
        cout << answer;
    else
        cout << -1;

    return 0;
}