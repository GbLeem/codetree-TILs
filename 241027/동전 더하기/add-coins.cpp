#include <iostream>
using namespace std;

int n, k;
int board[12];
int answer = 0;

int main() 
{
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    for(int i = n - 1; i >= 0; --i)
    {
        answer += k/board[i];
        k %= board[i];
    }
    cout << answer;
    return 0;
}