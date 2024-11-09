#include <iostream>
using namespace std;

int n, m;
int board[22][22];
int dx[8] = { 0,1,1,1,  0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1, -1,-1,0,1 };

void Print()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void Change(int x, int y)
{
    int maxValue = 0;
    int mX = 0;
    int mY = 0;

    for (int dir = 0; dir < 8; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        //범위 벗이난 경우
        if (nx < 0 || nx > n || ny < 0 || ny > n)
            continue;
        if (maxValue < board[nx][ny])
        {
            mX = nx;
            mY = ny;
            maxValue = board[nx][ny];
        }
    }

    board[mX][mY] = board[x][y];
    board[x][y] = maxValue;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    while (m--)
    {
        int cur = 1;
        while (cur <= n * n)
        {
            for (int i = 0; i < n; ++i)
            {
                bool ok = false;

                for (int j = 0; j < n; ++j)
                {
                    if (board[i][j] == cur)
                    {
                        Change(i, j);                    
                        ok = true;
                        cur++;
                        break;
                    }
                }
                if (ok)
                    break;
            }
        }
    }

    Print();
    return 0;
}