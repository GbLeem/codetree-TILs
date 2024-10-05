#include <iostream>
using namespace std;

int board[202][202];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if((i + 1) % 2 == 0) //파랑
        { 
            for(int j = x1; j < x2; ++j)
            {
                for(int k = y1; k < y2; ++k)
                {
                    board[j + 100][k + 100] = 2;
                }
            }
        }
        else //빨강
        {
            for(int j = x1; j < x2; ++j)
            {
                for(int k = y1; k < y2; ++k)
                {
                    board[j + 100][k + 100] = 1;
                }
            }
        }
    }

    int answer = 0;
    for(int i = 0; i <= 200; ++i)
    {
        for(int j = 0; j <= 200; ++j)
        {
            if(board[i][j] == 2)
                answer++;
        }
    }

    cout << answer;
    return 0;
}