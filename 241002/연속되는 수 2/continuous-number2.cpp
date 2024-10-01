#include <iostream>
using namespace std;

int board[1002];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    int answer = 1;
    for(int i = 1; i < n; ++i)
    {
        if(board[i] != board[i -1])
            answer++;
    }
    cout << answer;
    return 0;
}