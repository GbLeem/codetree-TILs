#include <iostream>
using namespace std;

int n;
int board[102][102];
int d[102][102];

int main() 
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
        }
    }

    d[1][1] = board[1][1];

    //행
    for(int i = 2; i <= n; ++i)
    {
        d[1][i] = min(d[1][i-1], board[1][i]);
    }

    //열
    for(int i = 2; i <= n; ++i)
    {
        d[i][1] = min(d[i-1][1], board[i][1]);
    }

    for(int i = 2; i <= n; ++i)
    {
        for(int j = 2; j <= n; ++j)
        {   
            d[i][j] = (min(d[i-1][j], d[i][j-1]), board[i][j]);
            if(i == n && j == n)
            {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    cout << d[n][n];
    return 0;
}