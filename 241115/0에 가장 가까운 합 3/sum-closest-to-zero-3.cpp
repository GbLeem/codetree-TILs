#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int board[100'002];
int answer = INT_MAX;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }
    sort(board, board + n);

    int en = n - 1;
    for (int st = 0; st < n; ++st)
    {
        while (en - 1 > st)
        {
            int dist = abs(board[en] + board[st]);
            if (dist > abs(board[en - 1] + board[st]))
                en--;
            else
                break;
        }
        answer = min(answer, board[en] + board[st]);
    }

    cout << answer;
    return 0;
}