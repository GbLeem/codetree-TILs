#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int board[30][30];
int vis[30][30];
vector<int> ans;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)  
        {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(board[i][j] == 1 && !vis[i][j])
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                int cnt = 1;

                while(!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    for(int dir = 0; dir < 4; ++dir)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || nx >=n || ny < 0 || ny >= n)
                            continue;
                        if(board[nx][ny] == 0 || vis[nx][ny])
                            continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                        cnt++;
                    }
                }
                ans.push_back(cnt);
            }
        }
    }   

    cout << ans.size() <<"\n";
    sort(ans.begin(), ans.end());
    for(auto a : ans)
    {
        cout << a << "\n";
    }

    return 0;
}