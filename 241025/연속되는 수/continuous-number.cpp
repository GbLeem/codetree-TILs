#include <iostream>
#include <algorithm>
using namespace std;

int n;
int isused[1'000'002];
int board[1002];
int tempBoard[1002];

int main() 
{
    cin >> n;

    int maxV = 0;
    int maxC = 0;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
        tempBoard[i] = board[i]; //복사용
        isused[board[i]] = 1;
        maxV = max(maxV, board[i]);
    }

    for(int i = 0; i <= maxV; ++i)
    {
        if(isused[i] == 1)
        {
            //i를 지우기
            for(int j = 0; j < n; ++j)
            {
                if(board[j] == i)
                    board[j] = -1;
            }

            ///2 7 -1 7 7 -1 7 5 7

            int tempC = 0;
            int same = board[0];

            for(int j = 0; j < n; ++j)
            {                                
                if(board[j] == -1)
                    continue;
                else if(same == board[j])
                    tempC++;
                
                else
                {   
                    same = board[j];
                    maxC = max(maxC, tempC);
                    tempC = 1;
                }
                
            } 
            for(int j = 0; j < n; ++j)
            {
                board[j] = tempBoard[j];
            }
            //cout << "i : "<<i << " Cnt: " <<maxC<<"\n";
        }

    }

    cout << maxC;

    return 0;
}