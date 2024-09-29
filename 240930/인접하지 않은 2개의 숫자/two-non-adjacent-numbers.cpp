#include <iostream>
using namespace std;

int board[102];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    int maxValue = 0;
    for(int i = 0; i < n - 2; ++i)
    {
        int temp = board[i];
        
        for(int j = i + 2; j < n; ++j)
        {
            if(j > n)
                break;
            if(maxValue < temp + board[j])
                maxValue = temp + board[j];
        }
    }
    
    cout << maxValue;
    return 0;
}