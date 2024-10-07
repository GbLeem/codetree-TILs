#include <iostream>
using namespace std;

int board[102][102];

bool InRange(int x, int y, int n)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() 
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i)
    {
        int r, c;
        cin >> r >> c;

        board[r - 1][c - 1] = 1;

        int temp = 0;

        if(InRange(r-1, c+1-1, n) && board[r-1][c] == 1)
            temp++;
        if(InRange(r+1-1, c-1, n) && board[r][c-1] == 1)
            temp++;
        if(InRange(r-1, c-1-1, n) && board[r-1][c-2] == 1)
            temp++;
        if(InRange(r-1-1, c-1, n) && board[r-2][c-1] == 1)
            temp++;

        if(temp == 3)
            cout << 1 << "\n";
        else
            cout<< 0 <<"\n";
    }

    return 0;
}