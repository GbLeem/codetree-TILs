#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, k;
int board[1'000'002];
int isused[1'000'002];

int main() 
{
    cin >> n >> k;

    for(int i = 0; i < k; ++i)
    {
        int s, e;
        cin >> s >> e;        

        isused[s] = 1;
        isused[e] = 1;

        board[s] -= 1;
        board[e] += 1;
    }

    for(int i = 1; i <= n; ++i)
    {
        if(!isused[i])
            board[i] = 0;
        else
        {
            board[i] += *max_element(board+1, board+1+n) - *min_element(board+1, board+1+n);
        }
    }  

    sort(board + 1,  board + n + 1);   

    cout << board[n / 2];
    return 0;
}