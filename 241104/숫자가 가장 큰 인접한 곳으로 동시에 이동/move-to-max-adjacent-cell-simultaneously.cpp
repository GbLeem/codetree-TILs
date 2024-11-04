#include <iostream>
using namespace std;

int n, m, t; //판 크기, 구슬 수, 반복 횟수
int board[22][22];
int countBoard[22][22];
int newCountBoard[22][22];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

void Move(int x, int y)
{
    int dir = 0;
    
    int mx = 0;
    int my = 0;
    int mv = 0;

    for(int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        //갈 수 있고
        if(InRange(nx, ny))
        {
            //큰 값이고, 원래 큰 값보다도 클때 값 리셋
            if(board[nx][ny] > board[x][y] && board[nx][ny] > mv)
            {
                mx = nx;
                my = ny;
                mv = board[nx][ny];
            }        
        }        
    }
    newCountBoard[mx][my]++;
}

int main()
{
    cin >> n >> m >> t;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < m; ++i)
    {
        int r, c;
        cin >> r >> c;
        countBoard[r-1][c-1] = 1;        
    }

    for(int ti = 0; ti < t; ++ti)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                //구슬이 있다면,
                if(countBoard[i][j] == 1)
                {
                    Move(i, j);
                }
            }
        }

        //count 배열 리셋
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                countBoard[i][j] = newCountBoard[i][j];
                if(countBoard[i][j] > 1)
                    m--;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                newCountBoard[i][j] = 0;                
            }
        }
    }
    cout << m;
    return 0;
}