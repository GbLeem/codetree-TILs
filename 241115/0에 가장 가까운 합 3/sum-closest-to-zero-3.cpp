#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int board[100'002];
int realAnswer = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }
    sort(board, board + n);

    int en = n - 1;
    int minValue = INT_MAX;
    
    for (int st = 0; st < n; ++st)
    {
        //현재 값보다 다음 값이 작으면 en을 내려줌
        while(en > 1 && abs(board[en - 1] + board[st]) <= abs(board[en] + board[st]))
        {
            en--;

            if(minValue == abs(board[en] + board[st]))            
                realAnswer = min(realAnswer, board[en] + board[st]);            
            else
            {
                if (minValue > abs(board[en] + board[st]))
                {
                    minValue = abs(board[en] + board[st]);
                    realAnswer = board[en] + board[st];
                }
            }      
            
            if(en == st)
                break;
        }
        //아닌 경우 st올리기
        if (minValue > abs(board[en] + board[st]))
        {
            minValue = abs(board[en] + board[st]);
            realAnswer = board[en] + board[st];
        }
    }

    cout << realAnswer;
    return 0;
}