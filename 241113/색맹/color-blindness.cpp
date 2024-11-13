#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n;
string board[102];
int vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int normal = 0;
int notcolor = 0;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> board[i];
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(!vis[i][j])
            {
                queue<pair<int, int>> q;
                normal++;
                q.push({i,j});
                vis[i][j] = 1;

                while(!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    for(int dir = 0; dir < 4; ++dir)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || nx > n || ny < 0 || ny > n)
                            continue;
                        if(board[nx][ny] != board[cur.first][cur.second])
                            continue;
                        if(vis[nx][ny])
                            continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(board[i][j] == 'R')
                board[i][j] = 'O';
            else if(board[i][j] == 'G')
                board[i][j] = 'O';
        }
    }

    for(int i = 0; i < n; ++i)
        fill(vis[i], vis[i] + n, 0);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(!vis[i][j])
            {
                notcolor++;
                queue<pair<int, int>> q;
                q.push({i,j});
                vis[i][j] = 1;

                while(!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    for(int dir = 0; dir < 4; ++dir)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || nx > n || ny < 0 || ny > n)
                            continue;
                        if(board[nx][ny] != board[cur.first][cur.second])
                            continue;
                        if(vis[nx][ny])
                            continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }

    cout << normal << " " << notcolor;
    return 0;
}