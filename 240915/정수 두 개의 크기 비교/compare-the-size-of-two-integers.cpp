#include <iostream>
#include <algorithm>
using namespace std;

int board[100002];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }
    
    sort(board, board + n, greater<int>());

    int st = 0;
    int en = 1;
    int ans = 0;

    while(1)
    {
        if(st == n - 1)
            break;
        if(board[st] * 0.9 <= board[en])
        {
            ans++;
            en++;
        }
        else
        {
            st++;
            en = st + 1;
        }
    }

    cout << ans;
    return 0;
}