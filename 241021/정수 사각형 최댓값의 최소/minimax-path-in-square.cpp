#include <iostream>
using namespace std;

int n;
int board[102][102];
int d[102][102];

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    d[0][0] = board[0][0];

    //1열
    for(int i = 1; i < n; ++i)
    {
        d[i][0] = max(d[i - 1][0], board[i][0]);
    }

    //1행
    for(int i = 1; i < n; ++i)
    {
        d[0][i] = max(d[0][i - 1], board[0][i]);
    }

    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            d[i][j] = max(min(d[i-1][j], d[i][j-1]), board[i][j]);
        }
    }

    // for(int i = 0; i < n; ++i)
    // {
    //     for(int j = 0; j < n; ++j)
    //     {
    //         cout << d[i][j]<<" ";
    //     }
    //     cout <<"\n";
    // }

    cout << d[n-1][n-1];

    return 0;
}