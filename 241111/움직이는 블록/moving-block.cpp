#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[10'002];
int answer = 0;

int main() 
{
    cin >> n;
    int sum = 0;
    int same = 0;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
        sum += board[i];
    }

    same = sum / n;

    for(int i = 0; i <n ;++i)
    {
        if(board[i] > same)
            answer += board[i] - same;
    }
    
    cout << answer;

    return 0;
}