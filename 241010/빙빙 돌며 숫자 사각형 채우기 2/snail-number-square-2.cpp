#include <iostream>
using namespace std;

int board[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() 
{
    int n, m;
    cin >> n >> m;

    //x y
    pair<int, int> cur = {0, 0};
    int dir = 0;
    int dist = 1;

    board[0][0] = dist;
    dist++;

    for(int i = 0; i < n * m - 1; ++i)
    {        
        if(cur.first + dx[dir] > n - 1 || cur.second + dy[dir]> m - 1 || cur.first + dx[dir] < 0 || cur.second + dy[dir] < 0)
        {
            dir = (dir + 1) % 4;
        }   
        if(board[cur.first + dx[dir]][cur.second + dy[dir]] != 0)
        {
            dir = (dir + 1)  %4;
        }
        cur.first = cur.first + dx[dir];
        cur.second = cur.second + dy[dir]; 

        if(board[cur.first][cur.second] == 0)
        {
            board[cur.first][cur.second] = dist;            

        }
        dist++;
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << board[i][j]<<" ";
        }
        cout << "\n";
    }

    return 0;
}