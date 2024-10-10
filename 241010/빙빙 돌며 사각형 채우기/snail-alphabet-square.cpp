#include <iostream>
using namespace std;

char board[102][102];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; //26개
int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            board[i][j] = '0';
        }        
    }

    int dir = 0;
    int index = 0; //25 max
    pair<int, int> cur = {0, 0};
    
    board[cur.first][cur.second] = alpha[index];
    //index++;
    for(int i = 1; i < m * n; ++i)
    {
        if(cur.first + dx[dir] > n - 1 || cur.second + dy[dir] > m - 1 || 
        cur.first + dx[dir] < 0 || cur.second + dy[dir] < 0 || board[cur.first + dx[dir]][cur.second + dy[dir]] != '0')
            dir = (dir + 1) % 4; //90도 회전

        index++;
        cur.first = cur.first + dx[dir];
        cur.second = cur.second + dy[dir];
        board[cur.first][cur.second] = alpha[index];

        index %= 26;
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << board[i][j] <<" ";
        }
        cout<<"\n";
    }

    return 0;
}