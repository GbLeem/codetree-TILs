#include <iostream>
#include <climits>
using namespace std;

int n, k;
int board[100'002];
int sum[100'002];

int GetSum(int s, int e)
{
    return sum[e] - sum[s-1];
}
int main() 
{
    cin >> n >> k;

    int cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> board[i];
    }
    sum[0] = 0;

    for(int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i-1] + board[i];
    }
    
    int ans = INT_MIN;
    for(int i = 1; i <= n - k + 1; ++i)
    {
        ans = max(ans, GetSum(i, i + k - 1));
    }
    
    cout << ans;

    return 0;
}