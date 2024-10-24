#include <iostream>
using namespace std;

int n, m;
int board[102];

void Bomb(int st, int en)
{
    int temp[102];
    int tempcur = 0;

    for (int i = 0; i < n; ++i)
    {
        if (st <= i && i < en)
            continue;
        temp[tempcur] = board[i];
        tempcur++;
    }

    for (int i = 0; i < n; ++i)
    {
        board[i] = 0;
    }

    n = tempcur;
    for (int i = 0; i < n; ++i)
    {
        board[i] = temp[i];
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[n - i - 1]; //2 1 3 2 2 3 3 3 2
    }

    while (1)
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
                    cnt = 1;
                    break;
                }
            }
        }
        //남은 것  
        if (cnt >= m)
        {
            Bomb(idx, idx + cnt);
            break;
        }

        if (!change)
            break;
    }

    cout << n << "\n";

    for (int i = n - 1; i >= 0; --i)
    {
        cout << board[i] << "\n";
    }
    return 0;
}