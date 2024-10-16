#include <iostream>
using namespace std;

int board[102][102];

int main()
{
    int n, m;
    cin >> n >> m;
    int answer = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    //연속하여 m개 이상의 동일한 원소 등장

    //x증가
    for (int i = 0; i < n; ++i)
    {
        int temp = board[i][0]; //시작점
        int cnt = 1;
        int maxCnt = 0;
        //y증가
        for (int j = 1; j < n; ++j)
        {
            if (temp != board[i][j])
            {
                maxCnt = max(maxCnt, cnt);
                temp = board[i][j];
                cnt = 1;
            }
            else
                cnt++;
        }
        maxCnt = max(maxCnt, cnt);
        if (maxCnt >= m)
            answer++;
    }

    //y증가
    for (int i = 0; i < n; ++i)
    {
        int temp = board[0][i]; //시작점
        int cnt = 1;
        int maxCnt = 0;

        //x증가
        for (int j = 1; j < n; ++j)
        {
            if (temp != board[j][i])
            {
                maxCnt = max(maxCnt, cnt);
                temp = board[j][i];
                cnt = 1;
            }
            else
                cnt++;
        }
        maxCnt = max(maxCnt, cnt);
        if (maxCnt >= m)
            answer++;
    }

    cout << answer;
    return 0;
}