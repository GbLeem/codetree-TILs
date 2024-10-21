#include <iostream>
#include <climits>
using namespace std;

int board[1002];
int d[1002];
int n;

int main() 
{
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> board[i];
        d[i] = INT_MIN;
    }

    d[1] = 1;
    //가장 긴 증가 부분 수열의 길이    
    //i에 도착했을 때 가장 긴 증가 수열의 길이
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j < i; ++j)
        {            
            if(board[i] > board[j])
                d[i] = max(d[i], d[j] + 1);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = max(ans, d[i]);

    cout << ans;


    return 0;
}