#include <iostream>
#include <string>
using namespace std;

char board[20][20];

int main() 
{
    int r, c;
    cin >> r >> c;

    int answer = 0;

    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 1; i < r; ++i)
    {
        for(int j = 1; j < c; ++j)
        {
            for(int k = i + 1; k < r - 1; ++k)
            {
                for(int l = j + 1; l < c - 1; ++l)
                {
                    if(board[0][0] != board[i][j] && board[i][j] != board[k][l] && board[k][l]!= board[r-1][c-1])
                        answer++;
                }
            }
        }
    }
    cout << answer;
    return 0;
}