#include <iostream>
using namespace std;

int n;
int r, c;
int board[202][202];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void Print()
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << board[i][j] <<" ";
        }
        cout << '\n';
    }
}
bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}
int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    cin >> r >> c;

    //터지기 1
    int bombsize = board[r-1][c-1];

    board[r-1][c-1] = 0;
    for(int dir = 0; dir < 4; ++dir)
    {
        for(int i = 1; i < bombsize; ++i)
        {   
            int nx = r-1 + dx[dir] * i;
            int ny = c-1 + dy[dir] * i;

            if(InRange(nx,ny))
            {
                board[nx][ny] = 0;
            }
        }
    }

    //Print();
    for(int col = 0; col < n; ++col)
    {   
        int temp[202];
        int tempRow = 0;
        //처리
        for(int row = n-1; row >=0; --row)
        {
            if(board[row][col] != 0)
            {
                temp[tempRow] = board[row][col];
                tempRow++;
            }            
        }
        //clear
        for(int row = 0; row < n; ++row)
        {
            board[row][col] = 0;
        }
        //copy
        //5 1 2 
        for(int i = 0; i < tempRow; ++i)
        {
            board[n - 1 - i][col] = temp[i];
        }
    }

    Print();
    return 0;
}