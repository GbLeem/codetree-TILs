#include <iostream>
#include <queue>
using namespace std;

int n, k;
int board[102][102];
int vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main() 
{
    cin >> n >> k; //상해있는 귤 수 k

    for(int i = 0; i < n; ++i)
        fill(vis[i], vis[i] + n, -2);

    //0그냥, 1은 귤, 2는 상한 귤
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];

            if(board[i][j] == 2)
            {
                q.push({i, j});
                vis[i][j] = 0;
            }
        }
    }

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx > n || ny < 0 || ny > n)
                continue;
            if(vis[nx][ny] != -2) //이미 방문했다면
                continue;
            if(board[nx][ny] == 0)
                continue;

            q.push({nx, ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(board[i][j] == 0) //빈칸이면
                cout << -1 << " ";
            else
                cout << vis[i][j] << " ";
        }
        cout << "\n";
    }
    

    return 0;
}