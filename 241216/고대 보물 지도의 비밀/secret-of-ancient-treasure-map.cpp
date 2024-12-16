#include <iostream>
using namespace std;

int n, k;
int board[100'005];
int dp[100'002][12]; //i 번째를 선택했을 때 음수가 j번 나타남
int answer = 0;

int main() 
{
    cin >> n >> k;

    for(int i = 1; i <= n; ++i)
    {
        cin >> board[i];        
    }

    for(int i =  1; i <= n; ++i)
    {
        if(board[i] >= 0)
        {
            for(int j = 0; j <= k; ++j)
            {
                dp[i][j] = max(dp[i-1][j] + board[i], dp[i][j]);
                answer = max(answer, dp[i][j]);
            }
        }
        else
        {
            for(int j = 0; j <= k; ++j)
            {
                dp[i][j] = max(dp[i-1][j-1] + board[i], dp[i][j]);
                answer = max(answer, dp[i][j]);
            }
        }
    }

    cout << answer;
    return 0;
}