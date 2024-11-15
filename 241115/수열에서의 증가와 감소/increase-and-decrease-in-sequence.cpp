#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[100'002];
int d1[100'002];
int d2[100'002];

void Print()
{
    for(int i = 1; i <= n; ++i)
    {
        cout << d1[i] <<" ";
    }
}
int main() 
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> board[i];
        d1[i] = 1;
        d2[i] = 1;
    }

    //1의 자리에 왔을 때 가장 긴 수열의 길이

    // d[1] = 1;
    // d[2] = 2;
    // d[3] = 3;
    // d[4] = 4;
    // d[5] = 5;
    // d[6] = 2;
    // d[7] = 3;
    // d[8] = 4;

    for(int i = 2; i <= n; ++i)
    {
        int cnt = 1;
        for(int j = i; j > 1; --j)
        {
            if(board[j] >= board[j - 1])            
                cnt++;            
            else
            {
                d1[i] = cnt;
                break;
            }
        }        
        d1[i] = cnt;
    }

    for(int i = 2; i <= n; ++i)
    {
        int cnt = 1;
        for(int j = i; j > 1; --j)
        {
            if(board[j] <= board[j - 1])            
                cnt++;            
            else
            {
                d2[i] = cnt;
                break;
            }
        }        
        d2[i] = cnt;
    }
    
    cout << max(*max_element(d1+1,d1+n+1), *max_element(d2+1, d2+n+1));

    return 0;
}