#include <iostream>
using namespace std;

int board[1000];

int main() 
{
    int n, t; 
    cin >> n >> t;

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        if(num > t)
            board[i] = num;    
        else
            board[i] = -1;    
    }
    
    int temp = 0;
    int answer = 0;

    for(int i = 1; i < n; ++i)
    {        
        if(board[0] > t)
            temp = 1;
        if(board[i] != -1 && board[i-1] != -1)
        {            
            if(board[i] > board[i - 1])
            {
                temp++;
            }
            else
            {
                answer = max(answer, temp);
                if(board[i] > t)
                    temp = 1;
                else
                    temp = 0;
            }                 
        }
    }
    cout << max(temp, answer);
    return 0;
}