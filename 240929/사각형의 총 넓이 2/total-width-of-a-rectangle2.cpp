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
        
        x1+=100;
        y1+=100;
        x2+=100;
        y2+=100;

        for(int i = x1; i <= x2 - 1; ++i)
        {
            for(int j = y1; j <= y2 - 1; ++j)
            {
                board[i][j] = 1;
            }
        }
    }

    int size = 0;
    for(int i = 0; i <= 200 ;++i)
    {
        for(int j = 0; j <= 200; ++j)
        {
            if(board[i][j] == 1)
                size++;
        }
    }

    cout << size;
    return 0;
}