#include <iostream>
using namespace std;

int board[25][25];

int CountCoin(int x, int y)
{
    int count = 0;
    for(int iy = y; iy < y + 3; ++iy)
    {
        for(int ix = x; ix < x + 3; ++ix)
        {
            if(board[ix][iy] == 1)
                count++;
        }
    }
    
    return count;
}


int main() 
{
    int n;
    cin >> n;

    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < n; ++x)
        {
            cin >> board[x][y];
        }
    }

    int maxCoin = 0;
    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < n; ++x)
        {
            if(x + 3 > n || y + 3 > n)
                continue;
            maxCoin = max(maxCoin, CountCoin(x,y));
        }        
    }
    cout<< maxCoin;
    return 0;
}