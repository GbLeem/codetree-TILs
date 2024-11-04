#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int board[100'002];
int answer = 0;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    sort(board, board + n);
    int en = n - 1;
    for (int st = 0; st < n; ++st)
    {
        while (en > st && board[st] + board[en] > k)
        {
            en--;
        }
        if (board[st] + board[en] == k)
            answer++;
        if (en == st)
            break;
    }

    cout << answer;
    return 0;
}