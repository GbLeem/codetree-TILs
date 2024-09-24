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

        for(int i = 0; i < n - 1; ++i)
        {
            if(board[i][index] == board[i + 1][index])
                colCount++;
            if(board[index][i] == board[index][i + 1])
                rowCount++;                
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