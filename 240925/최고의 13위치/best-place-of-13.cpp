#include <iostream>
using namespace std;

int board[25][25];

int CountCoins(int x, int y)
{
    int coins = 0;
    for(int ix = x; ix < x + 3; ++ix)
    {
        if(board[y][ix] == 1)
            coins++;
    }
    return coins;
}

int main() 
{
    int n;
    cin >> n;
    int maxCoins = 0;
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }
    
    for(int x = 0; x < n; ++x)
    {
        for(int y = 0; y < n; ++y)
        {
            if(x + 3 > n)
                continue;
            maxCoins = max(maxCoins, CountCoins(x, y));
        }
    }
    cout << maxCoins;

    return 0;
}