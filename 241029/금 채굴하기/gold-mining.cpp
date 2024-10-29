#include <iostream>
using namespace std;

int n, m;
int board[22][22];

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

int Count(int x, int y, int k)
{
    int vis[22][22];
    for (int i = 0; i < n; ++i)
        fill(vis[i], vis[i] + n, 0);
    int benefit = 0;

    benefit = board[x][y];
    vis[x][y] = 1;

    //가로줄
    for (int i = 1; i <= k; ++i)
    {
        int px = x;
        int py = y + i;
        int ny = y - i;

        if (InRange(px, py) && vis[px][py] == 0 && board[px][py] == 1)
        {
            vis[px][py] = 1;
            benefit++;
        }

        if (InRange(px, ny) && vis[px][ny] == 0 && board[px][ny] == 1)
        {
            vis[px][ny] = 1;
            benefit++;
        }
    }

    //세로줄
    for (int i = 1; i <= k; ++i) //x
    {
        for (int j = 0; j <= k - i; ++j)
        {
            int px = x + i;
            int nx = x - i;

            int py = y + j;
            int ny = y - j;

            if (InRange(px, py) && vis[px][py] == 0 && board[px][py] == 1)
            {
                vis[px][py] = 1;
                benefit++;
            }

            if (InRange(px, ny) && vis[px][ny] == 0 && board[px][ny] == 1)
            {
                vis[px][ny] = 1;
                benefit++;
            }

            if (InRange(nx, py) && vis[nx][py] == 0 && board[nx][py] == 1)
            {
                vis[nx][py] = 1;
                benefit++;
            }

            if (InRange(nx, ny) && vis[nx][ny] == 0 && board[nx][ny] == 1)
            {
                vis[nx][ny] = 1;
                benefit++;
            }
        }
    }

    return benefit;
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

    int answer = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                int cnt = Count(i, j, k);
                int costK = k * k + (k + 1) * (k + 1);

                //if (i == 2 && j == 2 && k == 2)
                //{
                //    cout << cnt * m - costK << "\n";
                //    cout << cnt << "\n";
                //}

               
                if (cnt * m - costK > 0)
                {
                    answer = max(answer, cnt);
                }
                
            }
        }
    }

    cout << answer;

    return 0;
}