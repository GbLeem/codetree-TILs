#include <iostream>
using namespace std;

int n, k;
int board[12];
int answer = 0;

int main() 
{
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    while(1)
    {
        for(int i = n - 1; i >= 0; --i)
        {
            if(board[i] <= k)
            {
                k -= board[i];
                answer++;                
                break;
            }
        }
        if(k == 0)
            break;

    }

    cout << answer;
    return 0;
}