#include <iostream>
using namespace std;

int board[102];

int main() 
{
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    //연속된 k개
    int maxSum = 0;
    for(int i = 0; i <= n - k; ++i)
    {
        int sum = 0;
        for(int j = i; j < i + k; ++j)
        {
            sum += board[j];
        }
        maxSum = max(maxSum, sum);
    }

    cout << maxSum;
    return 0;
}