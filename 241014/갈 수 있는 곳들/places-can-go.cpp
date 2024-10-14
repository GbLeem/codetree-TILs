#include <iostream>
#include <queue>
using namespace std;

int board[102][102];
int vis[102][102];
int dx[4] = {1, 0 ,-1, 0};
int dy[4] = {0, 1, 0, -1};

int answer = 0;
int n, k;

void BFS(int x, int y)
{
    queue<pair<int, int>> Q;
    vis[x][y] = 1;
    Q.push({x,y});

    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if(vis[nx][ny] == 1 || board[nx][ny] == 1) //방문했거나 이동 불가
                continue;
            
            answer++;
            Q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
}

int main() 
{
    cin >> n >> k;
    answer = k;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < k; ++i)
    {
        int r, c;
        cin >> r >> c;

        BFS(r - 1, c - 1);
    }
    
    cout << answer;
    return 0;
}