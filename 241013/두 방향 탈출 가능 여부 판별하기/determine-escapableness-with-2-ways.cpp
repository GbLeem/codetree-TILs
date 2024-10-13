#include <iostream>
using namespace std;

int board[102][102];
int vis[102][102];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int n, m;

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

bool CanGo(int x, int y)
{
    if(!InRange(x,y))
        return false;
    if(board[x][y] == 0 || vis[x][y] != 0) //못가거나 방문함
        return false;
    return true;
}

void DFS(int x, int y)
{
    for(int dir = 0; dir < 2; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(InRange(x, y))
            DFS(nx, ny);
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

    DFS(0,0);

    if(vis[n-1][m-1] == 1)
        cout << 1;
    else
        cout << 0;
    return 0;
}