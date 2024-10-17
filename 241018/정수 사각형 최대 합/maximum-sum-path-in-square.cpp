#include <iostream>
using namespace std;

int board[102][102];
int d[102][102];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int main() 
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
        }
    }

    //아래
    for(int i = 1; i <= n; ++i)
    {
        d[i][1] = d[i-1][1] + board[i][1];
    }

    //오른
    for(int i = 1; i <= n; ++i)
    {
        d[1][i] = d[1][i-1] + board[1][i];
    }

    //아래
    //d[i][j] = d[i-1][j] + a[i][j]
    //오른
    //d[i][j] = 
    //대각
    //d[i][j] = d[i-1][j-1] + a[i][j]

    for(int i = 2; i <= n; ++i)
    {
        for(int j = 2; j <= n; ++j)
        {
            d[i][j] = max(d[i-1][j], d[i][j-1]) + board[i][j];
        }
    }

    cout <<d[n][n];
    return 0;
}