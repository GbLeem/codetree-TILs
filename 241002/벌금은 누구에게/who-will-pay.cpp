#include <iostream>
using namespace std;

int board[102];

int main() 
{
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i)
    {
        board[i] = k;
    }

    for(int i = 0; i < m ; ++i)
    {
        int num;
        cin >> num;
        board[num]--;

        for(int j = 1; j <= n; ++j)
        {
            if(board[j] == 0)
            {
                cout << j;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}