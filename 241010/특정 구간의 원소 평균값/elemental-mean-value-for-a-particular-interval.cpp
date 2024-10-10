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
        for(int j = i; j < n; ++j) // 몇 개를 고를지 1 ~ 4 개
        {
            int tempSum = 0;
            int count = 0;
        
            for(int k = i; k <= j; ++k)
            {
                tempSum += board[k];                
            }
            double avg = (double)tempSum / (j - i + 1);

            for(int k = i; k <= j; ++k)
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