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
    while(cur < n)
    {
        if(board[cur] == 1)
        {
            answer++;
            cur = cur + 2 * m + 1;
        }
        if(cur > n)
            break;
    }
    cout << answer;
    return 0;
}