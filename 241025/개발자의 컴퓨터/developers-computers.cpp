#include <iostream>
#include <algorithm>
using namespace std;

int n, s, t, b;
int board[1002];

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> s >> t >> b;

        for(int j = s; j <= t; ++j)
        {
            board[j] += b;
        }        
    }    

    cout <<*max_element(board, board + 1002);
    return 0;
}