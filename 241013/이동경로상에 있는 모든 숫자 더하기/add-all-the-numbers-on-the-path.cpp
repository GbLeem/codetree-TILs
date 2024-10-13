#include <iostream>
using namespace std;

//N E S W
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int board[100][100];

bool InRange(int x, int y, int n)
{
    return (x < 0 || x >= n || y < 0 || y >= n);
}
int main() 
{
    int n, t;
    cin >> n >> t;

    string str;
    cin >> str;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    int dir = 0; //N
    pair<int, int> cur = {n/2, n/2};
    int answer = board[cur.first][cur.second];

    for(int i = 0; i < t; ++i)
    {
        if(str[i] == 'L')
        {
            dir = (dir + 3) % 4;
        }
        else if(str[i] == 'R')
        {
            dir = (dir + 1) % 4;
        }
        else //F
        {
            if(!InRange(cur.first + dx[dir], cur.second + dy[dir], n))
            {
                cur.first = cur.first + dx[dir];
                cur.second = cur.second + dy[dir];

                answer += board[cur.first][cur.second];
            }            
        }
    }

    cout << answer;
    return 0;
}