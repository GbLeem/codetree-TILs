#include <iostream>
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

    //(x,y)
    cin >> x1 >> y1 >> x2 >> y2;

    for(int i = x1; i < x2; ++i)
    {
        for(int j = y1; j < y2; ++j)
        {
            board[i + 1000][j + 1000] = 2;
        }
    }
    
    int maxX = 0;
    int maxY = 0;
    
    for(int i = 0; i < 2000; ++i) //x축
    {                
        int tempX = 0;
        bool check = false;

        for(int j = 0; j < 2000; ++j) //y축
        {
            if(board[i][j] == 1)
            {
                tempX++;            
                if(!check)
                {
                    maxY++;
                    check = true;
                }
            }                        
        }
        if(tempX > maxX)
            maxX = tempX;
    }

    //cout << maxX << "\n" << maxY << '\n';
    cout << maxX * maxY;
    return 0;
}