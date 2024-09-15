#include <iostream>
using namespace std;

int board[100002][2];
int n;
int d[100002][2]; //index, 고른 행

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int y = 0; y < 2; ++y)
    {
        for(int x = 0; x < n; ++x)
        {
            cin >> board[x][y];
        }
    }
    
    d[1][0] = board[0][0];
    d[1][1] = board[0][1];
    
    for(int i = 1; i <= n; ++i)
    {
        d[i][0] = max(d[i-1][1], d[i-2][1]) + board[i-1][0];
        d[i][1] = max(d[i-1][0], d[i-2][0]) + board[i-1][1];
    }
    
    cout <<max(d[n][0], d[n][1]);
    return 0;
}