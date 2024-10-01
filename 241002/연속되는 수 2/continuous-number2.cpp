#include <iostream>
using namespace std;

int board[1002];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    int maxValue = -1;
    int temp = 1;
    
    for(int i = 1; i < n; ++i)
    {        
        if(board[i] == board[i -1])
            temp++;
        else //같지 않을때
        {
            if(maxValue < temp)
                maxValue = temp;
            temp = 1;
            continue;            
        }                
    }
    if(maxValue < temp)
        maxValue = temp;
    cout << maxValue;

    return 0;
}