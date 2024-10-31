#include <iostream>
using namespace std;

int n, m;
int board[100'002];
int answer = 0;

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
        while(en < n && sum < m) 
        {
            sum += board[en];
            en++;

            if(sum == m)
            {
                answer++;            
                break;
            }
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