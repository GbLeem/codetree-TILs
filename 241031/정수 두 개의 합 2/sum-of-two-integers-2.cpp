#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int board[100'002];
int answer = 0;

int main() 
{
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
        cin >> board[i];

    sort(board, board + n);

    int en = 0;
    int cnt = 0;
    int sum = 0;

    for(int st = 0; st < n; ++st)
    {
        en = st;
        while(en < n && sum + board[en] <= k)
        {
            sum += board[en];
            cnt++;

            if(cnt == 2)
            {
                answer++;
                sum -= board[en];
                cnt--;
            }   
            en++;
        }
        sum -= board[st];
        cnt = 0;
    }

    cout << answer;
    return 0;
}