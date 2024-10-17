#include <iostream>
using namespace std;

int board[5][5];
int dir[5][5];
int n, r, c;
int answer = 0;
int dx[9] = { 100,-1, -1, 0, 1, 1, 1,   0, -1 };
int dy[9] = { 100,0,   1, 1, 1, 0, -1, -1, -1 };

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

bool CanGo(int x, int y, int num)
{
    return InRange(x, y) && board[x][y] > num;
}

void Choose(int x, int y, int cnt)
{       
    answer = max(answer, cnt);

    int tdir = dir[x][y];

    for(int i = 0; i < n ; ++i)
    {
        int nx = x + dx[tdir] * i;
        int ny = y + dy[tdir] * i;
        if(CanGo(nx, ny, board[x][y]))
            Choose(nx, ny, cnt + 1);
    }
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> dir[i][j];
        }
    }

    cin >> r >> c; //시작점
    
    Choose(r-1, c-1 ,0);
    cout <<answer;

    return 0;
}