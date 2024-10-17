#include <iostream>
using namespace std;

int n, m, q;
int board[102][102];

void Move(int r, char ch)
{
    if (ch == 'L')
    {
        int temp = board[r][m - 1];

        for (int i = m - 1; i > 0; --i)
        {
            board[r][i] = board[r][i - 1];
        }
        board[r][0] = temp;
    }
    else
    {
        int temp = board[r][0];

        for (int i = 0; i < m - 1; ++i)
        {
            board[r][i] = board[r][i + 1];
        }
        board[r][m - 1] = temp;
    }
}

void Print()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool UpCheck(int r)
{
    if (r > 0)
    {
        for (int i = 0; i < m; ++i)
        {
            if (board[r][i] == board[r - 1][i])
                return true;
        }
        return false;
    }
    return false;
}

bool DownCheck(int r)
{
    if (r < n)
    {
        for (int i = 0; i < m; ++i)
        {
            if (board[r][i] == board[r + 1][i])
                return true;
        }
        return false;
    }
    return false;
}

int main()
{
    cin >> n >> m >> q;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    //바람 
    for (int i = 0; i < q; ++i)
    {
        int r;
        char ch;
        cin >> r >> ch;

        //i == 0 일때만 위아래 체크

        Move(--r, ch);

        int tempR = r;
        char tempCh = ch;
        while (1)
        {
            if (UpCheck(r))
            {
                if (ch == 'L')
                {
                    Move(r - 1, 'R');
                    ch = 'R';
                }
                else if (ch == 'R')
                {
                    Move(r - 1, 'L');
                    ch = 'L';
                }
            }
            else
                break;
            r--;
        }

        while (1)
        {
            if (DownCheck(tempR))
            {
                if (tempCh == 'L')
                {
                    Move(tempR + 1, 'R');
                    tempCh = 'R';
                }
                else if (tempCh == 'R')
                {
                    Move(tempR + 1, 'L');
                    tempCh = 'L';
                }
            }
            else
                break;
            tempR++;
        }

        //이후로는 위 or 아래만 체크
    }

    Print();
    return 0;
}