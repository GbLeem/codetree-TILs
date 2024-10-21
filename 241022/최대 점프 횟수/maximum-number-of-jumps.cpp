#include <iostream>
using namespace std;

int n;
int board[1002];
int d[1002];

int main() 
{
    cin >> n; 
    for(int i = 1; i <= n; ++i)
    {
        cin >> board[i];
    }

    //i위치에 왔을때 최대 점프 횟수
    d[1] = 0;

    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j < i; ++j)
        {
            //현재 위치로 올 수 있을 때
            if(j + board[j] >= i)
            {
                d[i] = max(d[i], d[j] + 1);
            }
        }
        
    }
    
    int answer = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(i != 1 && d[i] == 0)
            break;
        answer = max(answer, d[i]);
        //cout << d[i]<<" ";
    }  

    cout << answer;
    return 0;
}