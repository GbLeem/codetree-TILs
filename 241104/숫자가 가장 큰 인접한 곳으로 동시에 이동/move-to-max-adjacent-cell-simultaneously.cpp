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
    int mx = -1;
    int my = -1;
    int mv = 0;

    for(int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        //갈 수 있고
        if(InRange(nx, ny))
        {
            //큰 값이고, 원래 큰 값보다도 클때 값 리셋
            if(board[nx][ny] > mv)
            {
                mx = nx;
                my = ny;
                mv = board[nx][ny]; //큰 값
            }        
        }        
    }

    //이동할 수 있는 경우
    if(mx != -1 && my != -1)
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

    //초기 구슬 배치
    for(int i = 0; i < m; ++i)
    {
        int r, c;
        cin >> r >> c;
        countBoard[r - 1][c - 1] = 1;       
    }

    //t번 반복
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

        //countboard 배열 리셋
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                countBoard[i][j] = newCountBoard[i][j];
                if(countBoard[i][j] > 1)
                    m-=countBoard[i][j];                    
            }
        }
        //newcountboard 배열 리셋
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