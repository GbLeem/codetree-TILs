#include <iostream>
using namespace std;

char board[15][4];

int main() 
{
    for(int i = 0; i < 15; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            board[i][j] = 'A';
        }
    }
    for(int i = 0; i < 4; ++i)
    {
        string str;
        cin >> str;

        for(int j = 0; j < str.size(); ++j)
        {
            board[j][i] = str[j];
        }
    }
    
    for(int i = 0; i < 15; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(board[i][j] != 'A')
                cout << board[i][j];
        }                
    }

    
    return 0;
}