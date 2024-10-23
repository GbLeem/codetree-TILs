#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

//합이 m
//n개 종류
int n, m;
int board[102];
int d[10002];

void Print()
{
    for(int i = 0; i <= m; ++i)
    {
        cout << d[i] << " ";
    }
    cout <<"\n";
}
int main() 
{
    cin >> n >> m;
    for(int  i = 1; i <= n; ++i)
    {
        cin >> board[i];    
    }

    for(int i = 0; i <= m; ++i)
    {
        d[i] = INT_MAX;
    }
    //지금까지 합이 i일때 최대 동전의 갯수
    d[0] = 0;

    //m을 만들기
    for(int i = 1; i <= m; ++i)
    {
        for(int j = n; j >= 1; --j) //1부터 모든 경우의 수
        {
            //만들려고 하는 숫자가 고른 숫자보다 클때
            if(i >= board[j])
            {   
                if(d[i - board[j]] == INT_MAX)
                    continue;
                d[i] = min(d[i], d[i - board[j]] + 1);
                //cout <<"d : " << i << " " << d[i - board[j]] + 1<<"\n";
            }
        }
    }

    //Print();
    if(d[m] == INT_MAX)
        cout << -1;
    else
        cout << d[m];
    return 0;
}