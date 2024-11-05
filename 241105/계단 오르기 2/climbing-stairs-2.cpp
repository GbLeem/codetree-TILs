#include <iostream>
#include <algorithm>
using namespace std;

//d[i][j] : i번째 숫자까지 고려했을때(선택 할지말지) 지금까지 j개 골랐을때 최대
int n;
int board[1002];
int d[1002][1002];//i번 자리까지왔을때 j개 골랐음
int cnt = 3;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> board[i];
    }

    //j가 제한조건, 연속해서 몇개 올랐는지    
    d[1][1] = board[1]; 
    d[2][0] = board[2]; //1계단을 안함
    d[2][2] = board[1] + board[1]; //1계단 두번 오름
    

    for (int i = 3; i <= n; ++i)
    {
        for (int j = 0; j <= 3; ++j)
        {   
            //두번째 전 값이 0아닌 경우 j는 상관 없음(두번 점프) 
            if(d[i - 2][j] != 0)            
                d[i][j] = max(d[i][j], d[i - 2][j] + board[i]);
            
            //j가 0 아니고 한개 전인데, j가 여유있을 때 (한번 점프)
            if(j && d[i - 1][j - 1] != 0)
                d[i][j] = max(d[i][j], d[i - 1][j - 1] + board[i]);
        }
    }

    cout << *max_element(d[n], d[n] + n);
    return 0;
}