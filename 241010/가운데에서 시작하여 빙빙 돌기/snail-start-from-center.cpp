#include <iostream>
using namespace std;

int board[10005][10005];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

void Print(int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;

    pair<int, int> cur = { n / 2, n / 2 };
    int dir = 0;
    int dist = 1;
    int length = 1;

    board[cur.first][cur.second] = dist;
    dist++;

    for (int i = 0; i < n * n; i++)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < length; ++k)
            {
                cur.first = cur.first + dx[dir];
                cur.second = cur.second + dy[dir];
                
                if (cur.first > n - 1 || cur.second > n - 1)
                {
                    Print(n);
                    return 0;
                }
                board[cur.first][cur.second] = dist;
                dist++;
            }
            dir = (dir + 1) % 4;
        }
        length++;
    }



    return 0;
}