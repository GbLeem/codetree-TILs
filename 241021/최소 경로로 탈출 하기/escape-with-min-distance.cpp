#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[102][102];
int vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() 
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            //0은 못지나감
            cin >> board[i][j];
            vis[i][j] = -1;
        }
    }    
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 0;

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(board[nx][ny] == 0 || vis[nx][ny] != -1)
                continue;
            q.push({nx, ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }        
    }

    cout << vis[n - 1][m - 1];
    return 0;
}