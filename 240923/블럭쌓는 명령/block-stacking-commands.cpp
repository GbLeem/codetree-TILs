#include <iostream>
#include <algorithm>
using namespace std;

int board[1000002];

int main() 
{
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < k; ++i)
    {
        int a, b;
        cin >> a >> b;

        for(int j = a; j <= b; ++j)
        {
            board[j]++;
        }
    }

    sort(board+1, board+n);

    cout << board[n/2];

    return 0;
}