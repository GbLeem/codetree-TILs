#include <iostream>
using namespace std;

int board1[2002];
int board2[2002];

int main() 
{
    int n, m;
    cin >> n >> m;
        
    int curTime = 0;
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
                board1[j] = curDist;
                curDist++;
            }
        }
        else //L
        {
            for(int j = curTime; j < curTime + num; ++j)
            {
                board1[j] = curDist;
                curDist--;
            }
        
        }
        curTime = curTime + num;
    }

    curTime = 0;
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
                board2[j] = curDist;
                curDist++;
            }
        }
        else //L
        {
            for(int j = curTime; j < curTime + num; ++j)
            {
                board2[j] = curDist;
                curDist--;
            }
        
        }
        curTime = curTime + num;
    }

    for(int i = 1; i <= 2000;++i)
    {
        if(board1[i] == board2[i])
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}