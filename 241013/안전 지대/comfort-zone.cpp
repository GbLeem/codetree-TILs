#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[55][55];
int vis[55][55];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<pair<int, int>> vec;
int temp = 0;

//first 가 갯수 second가 k
bool cmp(pair<int, int> a , pair<int, int> b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

bool CanGo(int x, int y, int k)
{
    if(!InRange(x,y))
        return false;
    if(vis[x][y] || board[x][y] <= k) //방문 했거나 k보다 낮은 곳 못감
        return false;
    return true;
}


void DFS(int x, int y, int k)
{    
    vis[x][y] = 1;

    for(int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(CanGo(nx, ny, k))
        {
            DFS(nx, ny, k);
        }
    }
}

int main() 
{
    cin >> n >> m;
    int maxNum = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            maxNum = max(maxNum, board[i][j]);
        }
    }
    
    //물의 높이
    for(int k = 1; k <= maxNum; ++k)
    {                 
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                //가능한 시작점
                if(vis[i][j] == 0 && board[i][j] > k) //방문안하고 높이가 높은 곳
                {          
                    temp++;
                    DFS(i, j, k);
                }
            }
        }
        //cout << temp<<"\n";
        vec.push_back({temp, k});          

        //vis temp 초기화
        temp = 0;                              
        for(int i = 0; i < n; ++i)
        {
            for(int  j = 0; j < m; ++j)
            {
                vis[i][j] = 0;
            }
        }
    }

    //안전 공간이 최대
    // for(auto v : vec)
    // {
    //     cout << v.first<<" "<<v.second<<"\n";
    // }
    sort(vec.begin(), vec.end(), cmp);
    cout << vec[0].second <<" "<<vec[0].first; //k부터 출력
    return 0;
}