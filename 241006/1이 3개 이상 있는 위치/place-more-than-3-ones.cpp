#include <iostream>
using namespace std;

int board[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool Range(int x, int y, int n)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    int answer = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int temp = 0;
            for(int dir = 0; dir < 4; ++dir)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                
                if(Range(i, j, n) && board[nx][ny] == 1)
                    temp++;
            }
            if(temp >= 3)
                answer++;            
        }
    }
    cout << answer;
    return 0;
}