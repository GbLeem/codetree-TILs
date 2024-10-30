#include <iostream>
using namespace std;

int n, m, q;
int board[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int r1, c1, r2, c2;

int tempBoard[102][102];

bool InRange(int x, int y)
{
    return (r1-1 <= x && x <= r2-1 && c1-1 <= y && y <= c2-1);
}

bool InRange2(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

void Print()
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++ j)
        {
            cout << board[i][j]<<" ";
        }
        cout <<'\n';
    }
}

void Change()
{    
    int x = r1 - 1;
    int y = c1 - 1;    

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0 ; j < m; ++j)
        {
            if(InRange(i, j))
            {
                int cur = board[i][j];
                int cnt = 1;

                for(int dir = 0; dir < 4; ++dir)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    
                    if(InRange2(nx, ny))
                    {
                        cur += board[nx][ny];
                        cnt++; 
                    }
                }

                tempBoard[i][j] = cur/cnt;
            }
            else
                tempBoard[i][j] = -1;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(tempBoard[i][j] == -1)
                continue;
            else
                board[i][j] = tempBoard[i][j];
        }
    }
}


int main() 
{
    cin >> n >> m >> q;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    //바람 수
    for(int i = 0; i < q; ++i)
    {    
        cin >> r1 >> c1 >> r2 >> c2; //좌측 상단 우측 하단
        
        int dir = 0;
        int x = r1 - 1;
        int y = c1 - 1;
        int temp = board[x][y];        

        while(1)
        {
            int nx = x + dx[dir]; //1
            int ny = y + dy[dir]; //2
                
            if(InRange(nx, ny))                
            {                                
                if(nx == r1 - 1 && ny == c1 - 1)
                {
                    board[x][y] = temp;
                    break;
                }
                board[x][y] = board[nx][ny];
                x = nx;
                y = ny;
            }
            else
            {
                dir = (dir + 1) % 4;                
            }   
        }           
        Change();
    }

    Print();

    return 0;
}