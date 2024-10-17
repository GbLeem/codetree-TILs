#include <iostream>
#include <queue>
using namespace std;

int n, k;
int r, c;
int board[102][102];
int vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int maxValue = 0;
int aX = 0;
int aY = 0;

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

void Choose(int x, int y, int cnt)
{    
    for(int i = 0; i < n; ++i)
        fill(vis[i], vis[i] + n, 0);

    if(cnt == k)
    {
        return;
    }
    ///최대 k개
    //BFS해서 가장 큰 숫자인데 가장 작은 곳 찾기
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = 1;
    int value = board[x][y]; //처음 시작값

    maxValue = 0;
    aX = 0;
    aY = 0;

    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            //범위안에 있는데 자신보다 큰 숫자일때 
            if(InRange(nx, ny) && board[nx][ny] >= value)                            
                continue;
            if(!InRange(nx, ny) || vis[nx][ny]) 
                continue;
            
            //새롭게 갈 곳
            Q.push({nx, ny});
            vis[nx][ny] = 1;

            //기존에 최대 값보다 큰 값이라면 리셋
            maxValue = max(maxValue, board[nx][ny]);          
            if(maxValue == 0)
            {
                aX = nx;
                aY = ny;
            }            
            //새로운 큰 값이 나타났다면, 
            else if(maxValue == board[nx][ny])
            {
                aX = nx;
                aY = ny;
            }   
        }
    }    
    //cout << maxValue << " "<<aX + 1<<" "<<aY + 1<<"\n";

    Choose(aX, aY, cnt + 1);
}

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    cin >> r >> c; //시작점

    Choose(r - 1, c - 1, 0); //x위치 y위치 cnt
    cout << aX + 1 <<" "<< aY + 1;

    return 0;
}