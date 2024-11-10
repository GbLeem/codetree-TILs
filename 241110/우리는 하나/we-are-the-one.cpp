#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k, u, d;
int board[10][10];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int vis[10][10];
int answer = 0;
int isused[100];
vector<int> ans;

int Check()
{
    int maxValue = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (vis[i][j] != -1)
                maxValue++;
        }
    }

    return maxValue;
}

void BFS()
{
    queue<pair<int, int>> q;

    for (auto a : ans)
    {
        int x = a / n;
        int y = a % n;

        q.push({ x, y });
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx > n || ny < 0 || ny > n)
                continue;
            if (vis[nx][ny] != -1)
                continue;
            int dist = abs(board[nx][ny] - board[cur.first][cur.second]);

            if (u <= dist && dist <= d)
            {
                q.push({ nx, ny });
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
            }
        }
    }
}

void Choose(int cur)
{
    if (cur == k + 1)
    {
        for (int i = 0; i < n; ++i)
            fill(vis[i], vis[i] + n, -1);
        
        BFS();
        answer = max(answer, Check());
        return;
    }

    for (int i = 0; i < n * n; ++i)
    {
        if (!isused[i])
        {            
            ans.push_back(i);
            isused[i] = 1;
            Choose(cur + 1);
            ans.pop_back();
            isused[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    Choose(1);


    cout << answer;

    return 0;
}