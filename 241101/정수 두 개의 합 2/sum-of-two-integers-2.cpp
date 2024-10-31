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

    int en = n - 1;    

    for(int st = 0; st < n; ++st)
    {
        while(en != 0 && board[st] + board[en] > k)
        {
            en--;
        }

        if(en <= st)
            break;

        answer += en - st;
    }

    cout << answer;
    return 0;
}