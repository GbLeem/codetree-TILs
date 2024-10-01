#include <iostream>
using namespace std;

int board[202][202];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int x1, y1;
        cin >> x1 >> y1; 

        for(int i = x1; i < x1 + 8; ++i)
        {
            for(int j = y1; j < y1 + 8; ++j)
            {
                board[i + 100][j + 100] = 1;
            }
        }
    }

    int answer = 0;
    for(int i = 0; i <= 200; ++i)
    {
        for(int j = 0; j <= 200; ++j)
        {
            if(board[i][j] == 1)
                answer++;
        }
    }

    cout << answer;
    return 0;
}