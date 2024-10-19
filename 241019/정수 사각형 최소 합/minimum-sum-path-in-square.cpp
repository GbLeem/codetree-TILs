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

    d[1][n] = board[1][n];

    //1행
    for(int i = n - 1; i >= 1; --i)
    {
        d[1][i] = d[1][i + 1] + board[1][i];
    }

    //n열
    for(int i = 2; i <= n; ++i)
    {
        d[i][n] = d[i - 1][n] + board[i][n];
    }
    
    //행은 증가
    for(int i = 2; i <= n; ++i)
    {
        //열은 감소
        for(int j = n - 1; j >= 1; --j)
        {
            d[i][j] = min(d[i-1][j], d[i][j+1]) + board[i][j];
        }
    }

    cout << d[n][1];
    return 0;
}