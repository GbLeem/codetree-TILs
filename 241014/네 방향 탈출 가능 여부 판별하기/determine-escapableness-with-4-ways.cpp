#include <iostream>
#include <queue>
using namespace std;

int board[102][102];
int vis[102][102];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

queue<pair<int, int>> Q;
int n, m;

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

bool CanGo(int x, int y)
{
    if(!InRange(x,y))
        return false;
    if(vis[x][y] || board[x][y] == 0)
        return false;
    return true;
}

void BFS()
{
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(CanGo(nx, ny))
            {
                Q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
}

int main() 
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    Q.push({0,0});
    vis[0][0] = 1;

    BFS();    

    cout << vis[n - 1][m - 1];
    
    return 0;   
}