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
            board[i + 1000][j + 1000] = 0;
        }
    }   
    
    int maxX = 0;
    int maxY = 0;

    for(int i = 0; i <= 2000; ++i) //y축
    {
        for(int j = 0; j <= 2000; ++j) //x축
        {
            if(board[i][j] == 1 && board[i][j + 1] == 1)
            {   
                maxY++;                
            }
            if(board[i][j] == 1 && board[i + 1][j] == 1)
            {
                maxX++;
            }
            
        }
    }
    cout <<maxX<<"\n"<<maxY<<'\n';
    cout << maxX * maxY;
    return 0;
}