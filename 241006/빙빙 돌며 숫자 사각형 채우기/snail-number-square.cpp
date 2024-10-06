#include <iostream>
using namespace std;

int board[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool InRange(int x, int y, int n, int m)
{
    return (0 <= x && x < m && 0 <= y && y < n);
}

int main() 
{
    int n, m;
    cin >> n >> m; //행 열

    int x = 0;
    int y = 0;
    int dir = 0;
    int value = 1;
    board[x][y] = value;

    for(int i = 2; i <= n*m; ++i)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(!InRange(nx, ny, n, m) || board[nx][ny] != 0)
            dir = (dir + 1) % 4;

        x = x + dx[dir];
        y = y + dy[dir];
        board[x][y] = ++value;
    }
    
    for(int i = 0 ;i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << board[i][j]<< " ";
        }
        cout << "\n";
    }
    return 0;
}