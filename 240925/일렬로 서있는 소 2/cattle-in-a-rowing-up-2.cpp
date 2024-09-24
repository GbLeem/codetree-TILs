#include <iostream>
using namespace std;

int board[102];

int main() 
{
    int n;
    int answer = 0;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    for(int i = 0; i <n; ++i)
    {
        int a1 = board[i];

        for(int j = i + 1; j < n; ++j)
        {
            if(board[j] >= a1)
            {
                int a2 = board[j];
                for(int k = j + 1; k < n; ++k)
                {
                    if(board[k] >= a2)
                    {
                        answer++;
                    }
                }
            }
        }
    }
    
    cout << answer;

    return 0;
}