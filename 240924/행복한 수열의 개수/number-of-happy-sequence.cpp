#include <iostream>
using namespace std;

int board[102][102];

int main() 
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    int index = 0;
    int answer = 0;

    while(index < n)
    {
        int rowCount = 0;
        int colCount = 0;

        int colbefore = board[0][index];
        int rowbefore = board[index][0];

        for(int i = 0; i < n ; ++i)
        {
            if(colbefore == board[i][index])
                colCount++;
            else
            {
                colbefore = board[i][index];                            
            }
        }
        for(int i = 0; i < n ; ++i)
        {
            if(rowbefore == board[index][i])
                rowCount++;
            else
            {
                rowbefore = board[index][i];                
            }
        }
        index++;

        if(colCount >= m)
            answer++;
        if(rowCount >= m)
            answer++;
    }   

    cout << answer;

    return 0;
}