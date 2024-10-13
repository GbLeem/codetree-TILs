#include <iostream>
using namespace std;

int board[102][102];
int vis[102][102];

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int n, m;

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

bool CanGo(int x, int y)
{
    if(!InRange(x,y))
        return false;
    if(vis[x][y] || board[x][y] == 0) //못가거나 방문하면 못감
        return false;
    return true;
}

void DFS(int x, int y)
{
    vis[x][y] = 1;
    
    for(int dir = 0; dir < 2; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(CanGo(nx, ny))
        {
            DFS(nx, ny);
        }
    }
}

int main() 
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    DFS(0, 0);

    if(vis[n - 1][m - 1] == 1) //방문 했으면
        cout << 1;
    else
        cout << 0;
    return 0;
}