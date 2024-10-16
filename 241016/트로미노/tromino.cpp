#include <iostream>
using namespace std;

int board[204][204];
int ans = 0;

int Count(int x, int y)
{
    int temp = 0;
    int answer = 0;
    //1자 세로
    for (int i = -1; i <= 1; ++i)
    {
        temp += board[x + i][y];
    }
    answer = max(temp, answer);
    temp = 0;

    //1자 가로
    for (int i = -1; i <= 1; ++i)
    {
        temp += board[x][y + i];
    }
    answer = max(temp, answer);
    temp = 0;

    //ㄴ자  1
    temp += board[x][y];
    temp += board[x - 1][y];
    temp += board[x][y + 1];

    answer = max(temp, answer);
    temp = 0;

    //ㄴ자 2
    temp += board[x][y];
    temp += board[x][y + 1];
    temp += board[x + 1][y];
    answer = max(temp, answer);
    temp = 0;

    //ㄴ자 3
    temp += board[x][y];
    temp += board[x][y - 1];
    temp += board[x + 1][y];
    answer = max(temp, answer);
    temp = 0;


    //ㄴ자 4
    temp += board[x][y];
    temp += board[x - 1][y];
    temp += board[x][y - 1];
    answer = max(temp, answer);
    temp = 0;

    return answer;
}


int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int temp = Count(i, j);
            if(temp > 3000)
                temp = 0;
            ans = max(ans, temp);            
        }
    }

    cout << ans;
    return 0;
}