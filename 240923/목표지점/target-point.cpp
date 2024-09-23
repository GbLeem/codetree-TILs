#include <iostream>
#include <queue>
using namespace std;

int board[505][505];
int dist[505][505];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> Q;

int main() 
{
    int n, m;
    cin >> n >> m;

    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < m; ++x)
        {
            cin >> board[x][y];
            dist[x][y] = -1;
        }
    }    

    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < m; ++x)
        {
            if(board[x][y] == 2)
            {
                Q.push({x,y});
                dist[x][y] = 0;

                while(!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();

                    for(int dir = 0; dir < 4; ++dir)
                    {
                        int nx = dx[dir] + cur.first;
                        int ny = dy[dir] + cur.second;

                        if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                            continue;
                        if(dist[nx][ny] != -1)
                            continue;
                        if(board[nx][ny] == 0)
                            continue;
                        Q.push({nx,ny});
                        dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    }
                }
            }
        }
    }
    
    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < m; ++x)  
        {
            if(board[x][y] == 0)
                cout << 0 <<" ";                            
            else
                cout << dist[x][y] <<" ";
        }
        cout <<"\n";
    }

    return 0;
}