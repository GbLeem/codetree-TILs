#include <iostream>
#include <climits>
using namespace std;

int board[2002][2002];

int main() 
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for(int i = x1; i < x2; ++i)
    {
        for(int j = y1; j < y2; ++j)
        {
            board[i + 1000][j + 1000] = 1;
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;

    for(int i = x1; i < x2; ++i)
    {
        for(int j = y1; j < y2; ++j)
        {
           board[i + 1000][j + 1000] = 0;
        }
    }
    int minX = INT_MAX;
    int maxX = 0;
    int minY = INT_MAX;
    int maxY = 0;

    for(int i = 0; i <= 2000; ++i)
    {
        for(int j = 0; j <= 2000; ++j)
        {
            if(board[i][j] == 1)
            {
                if(minX > i)
                    minX = i;
                if(minY > j)
                    minY = j;
                if(maxX < i)
                    maxX = i;
                if(maxY < j)
                    maxY = j;
            }
        }
    }

    cout << (maxX - minX + 1) * (maxY - minY + 1);
    return 0;
}