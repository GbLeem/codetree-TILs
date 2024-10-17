#include <iostream>
using namespace std;

int board[602];
int n, t;

int main() 
{
    cin >> n >> t;

    for(int i = 0; i < 3*n; ++i)
    {
        cin >> board[i];
    }

    for(int i = 0; i < t; ++i)
    {
        int temp = board[3 * n - 1];

        for(int j = 3*n-1; j > 0; --j)
        {
            board[j] = board[j-1];
        }
        board[0] = temp;
    }

    for(int i = 0; i < 3*n; ++i)
    {    
        if(i != 0 && i%n == 0)
            cout <<"\n";
        cout << board[i]<<" ";
    }

    return 0;
}