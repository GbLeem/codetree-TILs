#include <iostream>
using namespace std;

int board[1002];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i< n; ++i)
    {
        cin >> board[i];
    }

    int temp = 1;
    int answer = 0;

    for(int i = 1; i < n; ++i)
    {
        if(board[i] > board[i-1])
            temp++;
        else
        {
            temp = 1;
        }
        answer = max(answer, temp);
    }
    cout << answer;

    return 0;
}