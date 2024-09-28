#include <iostream>
using namespace std;

int board[2002];

int main() 
{
    int n;
    cin >> n;

    int start = 0;

    for(int  i = 0; i < n; ++i)
    {
        int num;
        char ch;
        cin >> num >> ch;        
        
        if(ch == 'R')
        {
            for(int j = start + 1000; j < (start + num + 1000); ++j)
            {
                board[j]++;
            }            
            start = start + num;
        }
        else
        {            
            for(int j = start + 1000; j > (start - num + 1000); --j)
            {
                board[j]++;
            }                                    
            start = start - num;
        }
    }
    
    int answer = 0;
    for(int i = 0; i < 2000; ++i)
    {
        if(board[i] >= 2)
            answer++;        
    }

    cout << answer;
    return 0;
}