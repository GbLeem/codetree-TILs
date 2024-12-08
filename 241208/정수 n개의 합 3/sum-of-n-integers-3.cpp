#include <iostream>
using namespace std;

int n, k;
int board[505][505];
int sumboard[505][505];
int answer = 0;

int getValue(int x1, int y1, int x2, int y2)
{
    return sumboard[x2][y2] - sumboard[x1-1][y2] - sumboard[x2][y1-1] + sumboard[x1-1][y1-1];
}
int main() 
{
    cin >> n >> k;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        int temp = 0;
        for(int j = 1; j <= n; ++j)
        {
            sumboard[i][j] = sumboard[i-1][j] + sumboard[i][j-1] -sumboard[i-1][j-1] + board[i][j];
        }
    }

    for(int i = 1; i <= n - k + 1; ++i)
    {
        for(int j = 1; j <= n - k + 1; ++j)
        {
            answer = max(answer, getValue(i, j, i + k - 1, j + k - 1));
        }        
    }

    cout << answer;
    return 0;
}