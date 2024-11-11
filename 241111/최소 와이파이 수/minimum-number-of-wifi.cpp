#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int board[102];
int answer = 0;

int main() 
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> board[i]; // 1 1 0 1 1 1
    }
    
    int cur = 1;

    while(1)
    {
        if(cur > n)
            break;
        if(board[cur] == 1)
        {
            answer++;
            cur = cur + 2 * m + 1;
        }
        else
            cur++;
    }
    cout << answer;
    return 0;
}