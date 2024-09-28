#include <iostream>
using namespace std;

int board[102];

int main() 
{
    int n;
    cin >> n;

    int start = 0;

    for(int  i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        string str;
        cin >> str;
        if(str[i] == 'R')
        {
            for(int j = start; j <= num; ++j)
            {
                board[j]++;
            }
            start = num;
        }
        else
        {            
            for(int j = start; j >= num; --j)
            {
                board[j]++;
            }
            start = num;
        }
    }

    int answer = 0;
    for(int i = 0; i < 102; ++i)
    {
        if(board[i] >=2)
            answer++;        
    }
    cout <<answer;
    return 0;
}