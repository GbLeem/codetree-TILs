#include <iostream>
#include <climits>
using namespace std;

int n, m;
int board[102];
int d[10'002];

int main() 
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> board[i];
    }
    d[0] = 0;
    for(int i = 1; i <= m; ++i)
    {
        d[i] = INT_MAX;
    }

    for(int j = 1; j <= n; ++j) //인덱스
    {
        for(int i = m; i >= 0; --i) //구하려고 하는 d
        {
            if(i >= board[j])
            {
                if(d[i - board[j]] == INT_MAX)
                    continue;
                d[i] = min(d[i], d[i - board[j]] + 1);
            }
        }
    }

    if(d[m] == INT_MAX)
        cout << -1;
    else
        cout << d[m];
    //0 1 2 3 4 5 6 7 8 9 10 11 12
    //0          
    return 0;
}