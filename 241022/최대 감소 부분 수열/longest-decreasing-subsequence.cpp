#include <iostream>
using namespace std;

int n;
int board[1002];
int d[1002];

int main() 
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> board[i];
        d[i] = 1;
    }

    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            if(board[i] < board[j]) //현재가 값이 더 작으면
            {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; ++i)
    {
        answer = max(answer, d[i]);
    }

    cout << answer;
    return 0;
}