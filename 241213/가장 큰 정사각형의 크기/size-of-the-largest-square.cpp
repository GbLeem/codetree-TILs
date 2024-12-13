#include <iostream>
using namespace std;

int n, m;
int board[505][505];
int answer = 0;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int length = 1;
            int x = i;
            int y = j;

            if (board[x][y] == 1)
            {
                while (y < m && board[x][y+length] == 1)
                {
                    length++;
                }

                bool check = true;
                for (int k = x; k < x + length; ++k)
                {
                    for (int l = y; l < y + length; ++l)
                    {
                        if (board[k][l] != 1)
                        {
                            check = false;
                            break;
                        }
                    }
                }


                if (check)
                    answer = max(answer, length);
            }
        }
    }

    cout << answer*answer;


    return 0;
}