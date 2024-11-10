#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int board[1'000'002];

int main() 
{
    cin >> n >> k;

    for(int i = 0; i < k; ++i)
    {
        int s, e;
        cin >> s >> e;

        for(int j = s; j <= e; ++j)
        {
            board[j]++;
            if(s == e)
                break;
        }
    }

    sort(board + 1,  board + n + 1);
    cout << board[n/2];
    return 0;
}