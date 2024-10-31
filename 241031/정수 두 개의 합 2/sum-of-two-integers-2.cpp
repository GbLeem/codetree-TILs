#include <iostream>
using namespace std;

int n, k;
int board[100'002];
int answer = 0;

int main() 
{
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
        cin >> board[i];

    int en = 0;
    int cnt = 0;
    int sum = 0;

    for(int st = 0; st < n; ++st)
    {
        en = st;
        while(en < n) //끝까지 안가고 / 0개 1개 선택 / 합이 k보다 작을 때
        {            
            //새로운 것 선택
            sum += board[en];
            cnt++;

            //그만 선택
            if(cnt == 2 && sum <= k)
            {
                answer++;      
                sum -= board[en];                
                cnt--;
            }    

            else if(sum > k || cnt > 2)
            {
                sum -= board[en];
                cnt--;
            }

            en++;            
        }        
        sum = 0;
        cnt = 0;    
    }

    cout << answer;
    return 0;
}