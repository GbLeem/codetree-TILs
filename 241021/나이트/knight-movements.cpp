#include <iostream>
#include <queue>
using namespace std;

int board[102][102];
int vis[102][102];
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int n;
int r1, c1;
int r2, c2;

int main() 
{
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    
    for(int i = 1; i <= n; ++i)
        fill(vis[i] + 1, vis[i] + n + 1, -1);

    queue<pair<int, int>> q;
    q.push({r1, c1});
    vis[r1][c1] = 0;


    //1부터 할거임
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(int dir = 0; dir < 8; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx <= 0 || nx > n || ny <= 0 || ny > n)
                continue;
            if(vis[nx][ny] != -1)
                continue;
            if(nx == r2 && ny == c2)
            {
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
                cout << vis[r2][c2];
                return 0;
            }
            q.push({nx, ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }

    cout << vis[r2][c2];

    return 0;
}