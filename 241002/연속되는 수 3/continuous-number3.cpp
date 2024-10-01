#include <iostream>
using namespace std;

int board[2002];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i + 1000]; 
    }

    int temp = 1;
    int answer = 0;

    for(int i = 1; i <= 2000; ++i)
    {
        if(board[i] * board[i-1] > 0)
            temp++;
        else
        {
            if(answer < temp)
                answer = temp;
            temp = 1;            
        }
    }

    cout << max(answer, temp);
    return 0;
}