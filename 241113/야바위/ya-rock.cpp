#include <iostream>
using namespace std;

int n;
int query[102][3];
int answer = 0;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> query[i][0] >> query[i][1] >> query[i][2];
    }

    //돌 넣은 곳

    for(int i = 1; i <= 3; ++i)
    {  
        int temp = 0;
        int board[4] ={};
        board[i] = 1;

        for(int j = 0; j < n; ++j)
        {
            swap(board[query[j][0]], board[query[j][1]]);

            if(board[query[j][2]] == 1)
                temp++;
        }
        answer = max(temp, answer);
    }

    cout << answer;
    return 0;
}