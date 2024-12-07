#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[102];
int answer = 0;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    // 1 3 4 7 11
    sort(board, board + n);

    //  1  3  4  7  11
    //l 0  2  1  3  4
    //r 2  1  3  4  0
    
    for(int i = 1; i < n; ++i)
    {
        if(board[i + 1] - board[i] > board[i] - board[i-1])
            answer++;
    }
    
    cout << answer;

    return 0;
}