#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int board[55];
int answer = 0;

int main() 
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }
    
    sort(board, board + n); // 1 2 3 4 5

    int temp = 0;
    for(int i = 0; i < n; ++i)
    {
        temp += board[i];
        if(temp > m)
        {
            answer++;
            temp = board[i];
        }
        if(temp == m)
        {
            answer++;
            temp = 0;
        }
    }
    if(temp != 0)
        answer++;
    cout << answer;

    return 0;
}