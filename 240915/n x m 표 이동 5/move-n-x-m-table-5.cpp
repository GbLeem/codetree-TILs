#include <iostream>
#include <queue>
using namespace std;

int board[102][102];
int dist[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

int main() 
{
    cin >> n >> m; //세로 가로

    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < m; ++x)
        {
            cin >> board[x][y];
            dist[x][y] = -1;
        }
    }
    
    queue<pair<int, int>> Q;
    Q.push({0,0});
    dist[0][0] = 1;

    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] == 0) //방문한 곳이거나, 벽일 때
                continue;            

            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }

    cout << dist[n-1][m-1];


    return 0;
}