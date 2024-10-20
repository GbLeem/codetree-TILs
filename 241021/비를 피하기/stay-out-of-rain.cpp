#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int board[102][102];
int vis[102][102];
int ans[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, h, m; //격자, 사람수, 비안오는곳

vector<pair<int,int>> vec;

int main() 
{
    cin >> n >> h >> m;    

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
            ans[i][j] = 0;
            if(board[i][j] == 2) //사람 이면
                vec.push_back({i, j});
        }
    }

    //BFS를 h번 반복해야함

    for(int i = 0; i < h; ++i)
    {
        bool cango = false;

        for(int j = 0; j < n; ++j)
            fill(vis[j], vis[j] + n, -1);
        
        queue<pair<int, int>> q;
        int st_x = vec[i].first;
        int st_y = vec[i].second;

        q.push({st_x, st_y});
        vis[st_x][st_y] = 0;

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for(int dir = 0; dir < 4; ++dir)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if(board[nx][ny] == 1 || vis[nx][ny] != -1) //벽일 때, 방문했을 때
                    continue;        
                if(board[nx][ny] == 3)
                {
                    vis[nx][ny] = vis[cur.first][cur.second] + 1;
                    ans[st_x][st_y] = vis[nx][ny];    
                    cango = true;
                    while(!q.empty())
                        q.pop();

                    break;
                }                        
                q.push({nx, ny});
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
            }

            if(!cango)
                ans[st_x][st_y] = -1;
        }

        
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {            
            cout << ans[i][j]<<" ";
        }
        cout <<"\n";
    }
    

    return 0;
}