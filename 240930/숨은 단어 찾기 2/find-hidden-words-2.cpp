#include <iostream>
using namespace std;

char board[55][55];

int main() 
{
    int n, m;
    cin >> n >> m;

    int answer = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    //cout << board[3][5]; -> L (r, c)
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(board[i][j] == 'L')
            {
                int r = i;
                int c = j;

                //up
                int cnt = 0;
                for(int k = r - 1; k > r - 3 ; --k)
                {
                    if(board[k][c] != 'E')            
                        break;           
                    else
                        cnt++;
                }
                if(cnt == 2)
                    answer++;

                //down
                cnt = 0;
                for(int k = r + 1; k < r + 3; ++k)
                {
                    if(board[k][c] != 'E')
                        break;
                    else
                        cnt++;
                }
                if(cnt == 2)
                    answer++;
                
                //right
                cnt = 0;
                for(int k = c + 1; k < c+ 3; ++k)
                {
                    if(board[r][k] != 'E')
                        break;
                    else
                        cnt++;
                }
                if(cnt == 2)
                    answer++;

                //left
                cnt = 0;
                for(int k = c - 1; k > c - 3; --k)
                {
                    if(board[r][k] != 'E')
                        break;
                    else
                        cnt++;
                }
                if(cnt == 2)
                    answer++;


                //up right
                cnt = 0;
                for(int k = 1; k < 3 ; ++k)
                {
                    if(board[r-k][c+k] != 'E')            
                        break;           
                    else
                        cnt++;
                }
                if(cnt == 2)
                    answer++;

                //up left 
                cnt = 0;
                for(int k = 1; k < 3 ; ++k)
                {
                    if(board[r-k][c-k] != 'E')
                        break;
                    else
                        cnt++;
                }
                if(cnt == 2)
                    answer++;
                
                //down right
                cnt = 0;
                for(int k = 1; k < 3 ; ++k)
                {
                    if(board[r+k][c+k] != 'E')
                        break;
                    else
                        cnt++;
                }
                if(cnt == 2)
                    answer++;

                //down left
                cnt = 0;
                for(int k = 1; k < 3 ; ++k)
                {
                    if(board[r+k][c-k] != 'E')
                        break;
                    else
                        cnt++;
                }
                if(cnt == 2)
                    answer++;
            }
        }
    }

    cout << answer;
    

    return 0;
}