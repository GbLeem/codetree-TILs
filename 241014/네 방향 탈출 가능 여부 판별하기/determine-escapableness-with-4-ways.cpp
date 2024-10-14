#include <iostream>
#include <queue>
using namespace std;

int board[102][102];
int vis[102][102];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

queue<pair<int, int>> Q;
int n, m;

void BFS()
{
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(vis[nx][ny] == 1 || board[nx][ny] == 0) //뱀이 있거나 이미 방문함
                continue;
            Q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
}

int main() 
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    Q.push({0,0});
    vis[0][0] = 1;

    BFS();    

    cout << vis[n - 1][m - 1];
    
    return 0;   
}