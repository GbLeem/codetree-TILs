#include <iostream>
using namespace std;

int n, m;
int board[102];

void Bomb(int st, int en)
{
    for (int i = 0; i < n; ++i)
    {
        if (st <= i && i < en)
            board[i] = 0;        
    }
}

bool Clear()
{
    int temp[102];
    int tempcur = 0;
    bool change = false;

    for(int i = 0; i < n; ++i)
    {
        if(board[i] == 0)
        {
            change = true;
            continue;
        }
        temp[tempcur] = board[i];
        tempcur++;
    }
    for(int i = 0; i < n; ++i)
    {
        board[i] = 0;
    }
    n = tempcur;
    for(int i = 0; i < n; ++i)
    {
        board[i] = temp[i];
    }
    return change;
}

int main() 
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[n - i - 1];
    }

    if(m == 1)
    {
        cout << 0;
        return 0;
    }

    while(1)
    {
        int cnt = 1;
        int idx = 0;
        bool first = true;
        bool change = false;

        for (int i = 0; i < n; ++i)
        {
            if (board[i] == board[i + 1])
            {
                cnt++;
                if (first)
                {
                    idx = i;
                    first = false;
                }
            }
            else if (board[i] != board[i + 1])
            {
                if (cnt >= m)
                {
                    Bomb(idx, idx + cnt); //i <= x < i + cnt            
                    change = true;
                    idx = 0;
                    cnt = 1;
                    first = true;
                }
                else
                {
                    cnt = 1;
                    idx = 0;
                    first = true;
                }
            }
        }
        if(!Clear())
        {
            break;
        }
    }

    cout << n << "\n";

    for(int i = n-1; i >= 0; --i)
    {
        cout << board[i] <<"\n";
    }
    

    return 0;
    
}