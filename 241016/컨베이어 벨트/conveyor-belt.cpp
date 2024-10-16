#include <iostream>
using namespace std;

int n, t;
int board[402];

//1 2 3 4 5 
//  1 2 3 4 
int main() 
{
    cin >> n >> t;

    for(int j = 0; j < 2*n; ++j)
        cin >> board[j];    

    for(int i = 0; i < t; ++i)
    {
        int temp = board[2 * n - 1]; //맨뒤

        for(int j = 2 * n - 1; j >0 ; --j)
        {   
            board[j] = board[j - 1];
        }
        board[0] = temp;
    }

    for(int i = 0; i < 2 * n; ++i)
    {
        if(i == n)
            cout <<"\n";
        cout << board[i] << " ";
    }


    return 0;
}