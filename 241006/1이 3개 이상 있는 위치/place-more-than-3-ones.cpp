#include <iostream>
using namespace std;

int board[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

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
                int nx = j + dx[dir];
                int ny = i + dy[dir];

                if(board[nx][ny] == 1)
                    temp++;
            }
            answer = max(answer, temp);
        }
    }
    cout << answer;
    return 0;
}