#include <iostream>
using namespace std;

int board[2002][2002];

int main() 
{
    for(int i = 0; i < 2; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int j = x1 + 1000; j <= x2 + 1000 -1; ++j)
        {
            for(int k = y1 + 1000; k <= y2 + 1000 - 1; ++k)
            {
                board[j][k] = 1;
            }
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int j = x1 + 1000; j <= x2 + 1000 - 1; ++j)
    {
        for(int k = y1 + 1000; k <= y2 + 1000 - 1; ++k)
        {
            board[j][k] = 0;
        }
    }

    int answer = 0;
    for(int i = 0; i <= 2000; ++i)
    {
        for(int j = 0; j <= 2000; ++j)
        {
            if(board[i][j] == 1)
                answer++;
        }
    }
    cout << answer;
    return 0;
}