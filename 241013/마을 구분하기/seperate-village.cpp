#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[30][30];
int vis[30][30];
int n;
int dx[2] = {0, 1};
int dy[2] = {1, 0};
vector<int> vec;
int cnt = 0;
int temp = 1;

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

bool CanGo(int x, int y)
{
    if(!InRange(x, y))
        return false;
    if(board[x][y] == 0 || vis[x][y])
        return false;
    return true;
}

void DFS(int x, int y)
{
    vis[x][y] = 1;

    for(int dir = 0; dir < 2; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(CanGo(nx, ny))
        {
            temp++;
            DFS(nx, ny);
        }
    }
}

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

    //0이 벽이다.

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(board[i][j] == 1 && !vis[i][j])
            {
                cnt++;
                DFS(i, j);
                vec.push_back(temp);
                temp = 1;
            }
        }
    }

    cout << cnt <<"\n";
    sort(vec.begin(), vec.end());

    for(auto v : vec)
        cout << v <<"\n"; 
    return 0;
}