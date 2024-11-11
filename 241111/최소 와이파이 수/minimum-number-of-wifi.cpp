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
    int cnt = 0;
    while(cur <= n)
    {
        if(board[cur] == 1)
        {
            cnt++;
        }        
        if(board[cur] == 0)
        {
            answer += (int)(ceil((double)cnt / (2 * m + 1)));
            cnt = 0;
        }
        cur++;
    }
    answer += (int)(ceil((double)cnt / (2 * m + 1)));
    cout << answer;
    return 0;
}