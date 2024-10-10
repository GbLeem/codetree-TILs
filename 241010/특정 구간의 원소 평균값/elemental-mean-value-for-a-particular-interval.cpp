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
    
    //n이 4인 경우
    for(int i = 0; i < n; ++i) // 시작점 0 ~ 3
    {
        for(int j = i + 1; j <= n; ++j) // 몇 개를 고를지 1 ~ 4 개
        {
            int tempSum = 0;
            int count = 0;
            int size = i + j;

            if(size > n) //2 + 4 > 4
                size = n;
            for(int k = i; k < size; ++k)
            {
                tempSum += board[k];
                count++;
            }
            double avg = (double)tempSum / count;

            for(int k = i; k < size; ++k)
            {
                if(board[k] == avg)
                {
                    answer++;                    
                }
            }
        } 
    }

    cout << answer;

    return 0;
}