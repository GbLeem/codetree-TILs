#include <iostream>
#include <climits>
using namespace std;

int n;
char board[6][6];
int d[10][10];
int d2[10][10];

void Print()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << d[i][j] << "  ";
        }
        cout << "\n";
    }
}

void Print2()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << d2[i][j] << "  ";
        }
        cout << "\n";
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    d[0][0] = board[0][0] - '0';
    d2[0][0] = board[0][0] - '0';

    //열 고정
    for (int i = 2; i < n; i += 2)
    {
        if (board[i - 1][0] == '+')
        {
            d[i][0] = d[i - 2][0] + (board[i][0] - '0');
            d2[i][0] = d2[i - 2][0] + (board[i][0] - '0');
        }
        else if (board[i - 1][0] == '-')
        {
            d[i][0] = d[i - 2][0] - (board[i][0] - '0');
            d2[i][0] = d2[i - 2][0] - (board[i][0] - '0');
        }
        else if (board[i - 1][0] == 'x')
        {
            d[i][0] = d[i - 2][0] * (board[i][0] - '0');
            d2[i][0] = d2[i - 2][0] * (board[i][0] - '0');
        }
    }

    //행 고정
    for (int i = 2; i < n; i += 2)
    {
        if (board[0][i - 1] == '+')
        {
            d[0][i] = d[0][i - 2] + (board[0][i] - '0');
            d2[0][i] = d2[0][i - 2] + (board[0][i] - '0');
        }
        else if (board[0][i - 1] == '-')
        {
            d[0][i] = d[0][i - 2] - (board[0][i] - '0');
            d2[0][i] = d2[0][i - 2] - (board[0][i] - '0');
        }
        else if (board[0][i - 1] == 'x')
        {
            d[0][i] = d[0][i - 2] * (board[0][i] - '0');
            d2[0][i] = d2[0][i - 2] * (board[0][i] - '0');
        }
    }

    
    //Print();

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int temp1 = 0;
            int temp2 = 0;
            int mintemp1 = 0;
            int mintemp2 = 0;

            //행 부호                        
            if (board[i][j - 1] == '+')
            {
                if (j - 2 >= 0)
                {
                    temp1 = max(d[i - 1][j - 1] + (board[i][j] - '0'), d[i][j - 2] + (board[i][j] - '0'));
                    mintemp1 = min(d2[i - 1][j - 1] + (board[i][j] - '0'), d2[i][j - 2] + (board[i][j] - '0'));
                }
                else
                {
                    temp1 = d[i - 1][j - 1] + (board[i][j] - '0');
                    mintemp1 = d2[i - 1][j - 1] + (board[i][j] - '0');
                }
            }
            else if (board[i][j - 1] == '-')
            {
                if (j - 2 >= 0)
                {
                    temp1 = max(d[i - 1][j - 1] - (board[i][j] - '0'), d[i][j - 2] - (board[i][j] - '0'));
                    mintemp1 = min(d2[i - 1][j - 1] - (board[i][j] - '0'), d2[i][j - 2] - (board[i][j] - '0'));
                }
                else
                {
                    temp1 = d[i - 1][j - 1] - (board[i][j] - '0');
                    mintemp1 = d2[i - 1][j - 1] - (board[i][j] - '0');
                }
            }
            else if (board[i][j - 1] == 'x')
            {
                if (j - 2 >= 0)
                {
                    temp1 = max(d[i - 1][j - 1] * (board[i][j] - '0'), d[i][j - 2] * (board[i][j] - '0'));
                    mintemp1 = min(d2[i - 1][j - 1] * (board[i][j] - '0'), d2[i][j - 2] * (board[i][j] - '0'));
                }
                else
                {
                    temp1 = d[i - 1][j - 1] * (board[i][j] - '0');
                    mintemp1 = d2[i - 1][j - 1] * (board[i][j] - '0');
                }
            }
            //열 부호            
            if (board[i - 1][j] == '+')
            {
                if (i - 2 >= 0)
                {
                    temp2 = max(d[i - 1][j - 1] + (board[i][j] - '0'), d[i - 2][j] + (board[i][j] - '0'));
                    mintemp2 = min(d2[i - 1][j - 1] + (board[i][j] - '0'), d2[i - 2][j] + (board[i][j] - '0'));
                }
                else
                {
                    temp2 = d[i - 1][j - 1] + (board[i][j] - '0');
                    mintemp2 = d2[i - 1][j - 1] + (board[i][j] - '0');
                }
            }
            if (board[i - 1][j] == '-')
            {
                if (i - 2 >= 0)
                {
                    temp2 = max(d[i - 1][j - 1] - (board[i][j] - '0'), d[i - 2][j] - (board[i][j] - '0'));
                    mintemp2 = min(d2[i - 1][j - 1] - (board[i][j] - '0'), d2[i - 2][j] - (board[i][j] - '0'));
                }
                else
                {
                    temp2 = d[i - 1][j - 1] - (board[i][j] - '0');
                    mintemp2 = d2[i - 1][j - 1] - (board[i][j] - '0');
                }
            }
            if (board[i - 1][j] == 'x')
            {
                if (i - 2 >= 0)
                {
                    temp2 = max(d[i - 1][j - 1] * (board[i][j] - '0'), d[i - 2][j] * (board[i][j] - '0'));
                    mintemp2 = min(d2[i - 1][j - 1] * (board[i][j] - '0'), d2[i - 2][j] * (board[i][j] - '0'));
                }
                else
                {
                    temp2 = d[i - 1][j - 1] * (board[i][j] - '0');
                    mintemp2 = d2[i - 1][j - 1] * (board[i][j] - '0');
                }
            }

            d[i][j] = max(temp1, temp2);
            d2[i][j] = min(mintemp1, mintemp2);
        }
    }
    cout << d[n-1][n-1] << " "<<d2[n-1][n-1];
    
    
    return 0;
}