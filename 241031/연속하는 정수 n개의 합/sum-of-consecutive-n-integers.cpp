#include <iostream>
using namespace std;

int n, m;
int board[100'002];
int answer = 0;

//연속하는! 이라는 키워드
int main() 
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    int en = 0;
    int sum = 0;

    for(int st = 0; st < n; ++st)
    {
        while(en < n && sum + board[en] <= m)
        {
            sum += board[en];
            en++;
            //완성
            if(sum == m)            
            {        
                answer++;                         
                break;
            }                                    

            //st를 움직여야 함
            if(sum > m)
            {
                break;            
            }
        }   
        sum -= board[st];
    }

    cout << answer;

    return 0;
}