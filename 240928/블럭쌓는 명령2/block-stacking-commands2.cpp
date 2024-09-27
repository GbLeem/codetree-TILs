#include <iostream>
#include <algorithm>
using namespace std;

int board[102];

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
    
    int answer = *max_element(board + 1, board + n);
    cout << answer;
    return 0;
}