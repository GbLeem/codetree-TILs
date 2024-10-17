#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k, m; //격자, 시작점 수, 치워야 할 돌
int board[102][102];
int tempBoard[102][102];
int vis[102][102];
vector<pair<int,int>> start;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int answer = 0;

int BFS(int x, int y)
{
    int cnt = 0;
    int tempM = m;
    queue<pair<int, int>> Q;

    Q.push({x,y});
    vis[x][y] = 1;

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
            if(vis[nx][ny] == 1)
                continue;
            if(board[nx][ny] == 1) //못가는 경우
            {
                if(tempM > 0)
                {
                    tempM--;
                    cnt++;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }                        
            }                        
            else
            {
                cnt++;
                Q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }

    return cnt;
}

void Choose(int cur)
{        
    //m개 다 지운 경우
    if(cur == m + 1)
    {
        for(int i = 0; i < n; ++i)
        {
            answer = max(answer, BFS(start[i].first, start[i].second));
        }
    }

    //n*n보다 작은 숫자
    for(int i = 0; i < n * n; ++i)
    {
        int x = i / n;
        int y = i % n;

        //돌인 경우 (1인 경우)
        if(board[x][y] == 1)
        {
            board[x][y] = 0;
            Choose(cur + 1);
        }
    }
}
int main() 
{
    cin >> n >> k >> m;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
            tempBoard[i][j] = board[i][j];
        }
    }
    
    for(int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x>> y;
        start.push_back({x, y});
    }

    Choose(1);

    cout << answer;

    return 0;
}