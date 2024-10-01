#include <iostream>
using namespace std;

int board1[1000002];
int board2[1000002];

int main() 
{
    int n, m;
    cin >> n >> m;
        
    int curTime = 1;
    int curDist = 0;

    for(int i = 0; i < n; ++i)
    {
        char ch;
        int num;
        cin >> ch >> num;

        //j초에 어디에 있었는지
        if(ch == 'R')
        {
            for(int j = curTime; j < curTime + num; ++j)
            {
                board1[j] = ++curDist;                
            }
        }
        else //L
        {
            for(int j = curTime; j < curTime + num; ++j)
            {
                board1[j] = --curDist;                
            }
        
        }
        curTime = curTime + num;
    }

    curTime = 1;
    curDist = 0;

    for(int i = 0; i < m; ++i)
    {
        char ch;
        int num;
        cin >> ch >> num;

        //j초에 어디에 있었는지
        if(ch == 'R')
        {
            for(int j = curTime; j < curTime + num; ++j)
            {
                board2[j] = ++curDist;                
            }
        }
        else //L
        {
            for(int j = curTime; j < curTime + num; ++j)
            {
                board2[j] = --curDist;                
            }
        
        }
        curTime = curTime + num;
    }
    
    // for(int i = 0; i <= 13; ++i)
    // {
    //     cout << board1[i] <<" ";        
    // }
    // cout <<'\n';
    // for(int i = 0; i <= 13; ++i)
    // {
    //     cout << board2[i] <<" ";        
    // }

    for(int i = 1; i <= 1000000;++i)
    {
        if(board1[i] != 0 && board2[i] != 0 && board1[i] == board2[i])
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}