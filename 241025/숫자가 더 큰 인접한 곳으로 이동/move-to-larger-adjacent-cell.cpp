#include <iostream>
using namespace std;

int board[102][102];
int n, r, c;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() 
{
    cin >> n >> r >> c; // 4 2 2 
    
    r -= 1; // 1
    c -= 1; // 1

    for(int i = 0 ; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    int maxValue = board[r][c];        
    int maxX = 0;
    int maxY = 0;
    cout << maxValue << " ";

    while(1)
    {
        int change = false;
        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = r + dx[dir];
            int ny = c + dy[dir];

            if(InRange(nx, ny) && board[nx][ny] > maxValue)
            {
                change = true;
                maxValue = board[nx][ny];
                maxX = nx;
                maxY = ny;
                cout << maxValue <<" ";
                break;
            }            
        }
        r = maxX;
        c = maxY;


        if(!change)
            break;
    }
    

    return 0;
}