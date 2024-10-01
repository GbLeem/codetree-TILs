#include <iostream>
using namespace std;

int board[1002];

int main() 
{  
    int n, t;
    cin >> n >> t;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }   
    
    int temp = 0;
    int answer = 0;

    for(int i = 0; i < n; ++i)
    {
        if(i >= 1 && board[i] > board[i - 1])
        {
            if(board[i - 1] > t)
                temp++;
            else
            {
                answer = max(answer, temp);                
                
                if(board[i] > t)
                    temp = 1;
                else
                    temp = 0;    
            }
        }
        else
        {
            answer = max(answer, temp);
            if(board[i] > t)
                temp = 1;
            else
                temp = 0;
        }
        answer = max(answer, temp);
    }
    cout << answer;
    return 0;
}