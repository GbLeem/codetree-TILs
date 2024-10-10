#include <iostream>
using namespace std;

int board[102];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i]; // 1 1 2 3 
    }

    int answer = 0;
    for(int i = 0; i < n; ++i) // 시작점
    {
        for(int j = i + 1; j <= n; ++j) // 몇 개를 고를지 1 ~ n 개
        {
            int tempSum = 0;
            for(int k = i; k < j; ++k) // i부터 j개
            {
                tempSum += board[k];
            }
            int avg = tempSum / j;
            
            for(int k = i; k < j; ++k)
            {
                if(board[k] == avg)
                {
                    answer++;
                    break;
                }
            }
        } 
    }
    cout << answer;
    return 0;
}