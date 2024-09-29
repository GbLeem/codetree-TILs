#include <iostream>
#include <algorithm>
using namespace std;

int board[25];

int Sum(int a, int b, int c)
{  
    int div = 10;
    int sum = 0;

    while(1)
    {
        int temp = 0;
        int check = 0;
        
        temp = a % div + b % div + c % div;
        check = (a % div) / (div/10) + (b % div) / (div/10) + (c % div) / (div/10);
        sum += temp;
        
        if(check >= 10)
        {        
            return -1;
        }

        a = a - a % div;
        b = b - b % div;
        c = c - c % div;

        if(a == 0 && b == 0 && c == 0)
            break;

        div *= 10;
    }    
    
    return sum;
}

int main() 
{
    int n;
    int maxValue = 0;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            for(int k = j + 1; k < n; ++k)
            {
                maxValue = max(Sum(board[i], board[j], board[k]), maxValue);
            }
        }
    }
    if(maxValue == 0)
        cout << -1;
    else
        cout << maxValue;

    return 0;
}