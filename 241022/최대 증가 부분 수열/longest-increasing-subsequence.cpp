#include <iostream>
#include <climits>
using namespace std;

int board[102];
int d[102];
int n;

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
        d[i] = INT_MIN;
    }

    //가장 긴 증가 부분 수열의 길이
    d[0] = 0;
    //i에 도착했을 때 가장 긴 증가 수열의 길이
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(d[j] == INT_MIN)
                continue;
            if(j + board[j] >= i)
                d[i] = max(d[i], d[j] + 1);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i)
        ans = max(ans, d[i]);

    cout << ans;


    return 0;
}