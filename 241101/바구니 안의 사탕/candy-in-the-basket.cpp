#include <iostream>
using namespace std;

int n, k;
int board[1'000'002];
int maxPos = 0;
int answer = 0;

int main() 
{
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        int cnt, pos;
        cin >> cnt >> pos;
        board[pos] = cnt;   
        maxPos = max(maxPos, pos); //15    
    }    
    // for(int i = 0; i <= maxPos; ++i)
    //     cout << board[i]<<" ";
    // cout <<"\n";

    int en = 0;
    int sum = 0;

    for(int st = 0; st <= maxPos; ++st) //시작 position
    {         
        while(en <= st + 2 * k && en <= maxPos) //범위 안에 있고, 최대값 안넘었을 때
        {
            sum += board[en];
            en++;
        }
        //cout << "st " << st <<" en: "<<en<< " sum " << sum<< "\n";
        
        answer = max(answer, sum);
        sum -= board[st];             
    }
    
    cout << answer;

    return 0;
}