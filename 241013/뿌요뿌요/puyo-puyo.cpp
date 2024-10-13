#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[102][102];
int vis[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;
int cnt = 0; //터지즌 블럭 종류 갯수
int temp = 1; //최대 블럭의 크기
vector<int> vec; //temp 모으는 벡터

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

bool CanGo(int x, int y)
{
    if(!InRange(x, y))
        return false;
    if(vis[x][y]) //방문 했거나 같은 숫자 아니면
        return false;
    return true;
}

void DFS(int x, int y)
{
    vis[x][y] = 1;

    for(int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(CanGo(nx, ny))
        {
            if(board[nx][ny] == board[x][y])
            {
                temp++; //넓이
                DFS(nx, ny);
            }
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

    //터지게 되는 블록 수, 최대 블록 크기

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(!vis[i][j])
            {
                int data = board[i][j];

                DFS(i, j);
                if(temp >= 4)
                {
                    vec.push_back(temp);                
                    cnt++;
                }
                temp = 1;                
            }
        }
    }

    cout << cnt << " "<<*max_element(vec.begin(), vec.end());
    return 0;
}