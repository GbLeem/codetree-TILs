#include <iostream>
#include <climits>
using namespace std;

int board[102];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i]; //사람 수
    }

    int minSum = INT_MAX;

    for(int i = 0; i < n; ++i)
    {
        int select = i + 1; //i번째 사람
        int tempSum = 0;

        //선택된 사람 이외의 사람들 j
        for(int j = 0; j < n; ++j)
        {
            tempSum += (abs(j + 1 - select) * board[j]);
        }

        if(minSum > tempSum)
            minSum = tempSum;
    }

    cout << minSum;

    return 0;
}