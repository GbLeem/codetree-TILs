#include <iostream>
using namespace std;

int n;
int board[33][33];
int dp[33][33][3]; //가로 대각 세로

void Print()
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j<= n; ++j)
        {
            cout << dp[i][j][0] <<" ";
        }
        cout <<"\n";
    }
}
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

    //0은 빈칸 1은 벽
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    dp[0][0][2] = 0;

    dp[1][1][0] = 0;
    dp[1][1][1] = 0;
    dp[1][1][2] = 0;

    dp[1][2][0] = 1;
    dp[1][2][1] = 0;
    dp[1][2][2] = 0;

    //x y dir
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 3; j <= n; ++j)
        {                                 
            //가로                  
            if(board[i][j] == 0)
            {
                dp[i][j][0] += dp[i][j-1][0];
                dp[i][j][0] += dp[i][j-1][1]; 
            }
        
            if(board[i][j] == 0 && board[i-1][j] == 0 && board[i][j-1] == 0)
            {
                dp[i][j][1] += dp[i-1][j-1][0]; 
                dp[i][j][1] += dp[i-1][j-1][1]; 
                dp[i][j][1] += dp[i-1][j-1][2]; 
            }

            if(board[i][j] == 0)
            {
                dp[i][j][2] += dp[i-1][j][1];
                dp[i][j][2] += dp[i-1][j][2]; 
            }
                    
        }
    }
    
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    return 0;
}