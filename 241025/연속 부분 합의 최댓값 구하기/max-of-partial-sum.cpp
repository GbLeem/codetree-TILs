#include <iostream>
using namespace std;


//d는 선택한 수열의 마지막이 i일때 최대 점수
//d[i] = max(d[i-1]+a[i], 2*a[i]);

int n;
int board[100'002];
int d[100'002];

int main() 
{
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> board[i];
    }

    d[1] = board[1];
    //d[2] = max(d[1] + board[1], board[1]);
    for(int i = 2; i <= n; ++i)
    {
        d[i] = max(d[i-1] + board[i], board[i]);
    }

    cout << d[n];
    return 0;
}