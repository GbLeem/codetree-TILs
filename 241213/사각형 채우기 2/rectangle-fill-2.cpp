#include <iostream>
using namespace std;

int dp[1002];
int n;

int main() 
{
    cin >> n;

    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;

    for(int i = 4; i <= n; ++i)
    {
        dp[i] = (dp[i-1] + dp[i-2]*2) %10'007;
    }

    cout << dp[n];

    return 0;
}