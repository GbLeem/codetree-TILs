#include <iostream>
#include <algorithm>
using namespace std;

int board[1002][3];
int d[1002][3];   //a :0, b: 1, c: 2
int first[1002];

int main() 
{
    int n;
    int a, b, c;

    cin >> n; //길이가 n임

    for(int i = 1; i <= n; ++i)
    {
        cin >> board[i][0] >> board[i][1] >> board[i][2]; 
    }

    d[1][0] = board[1][0]; //첫번째 a
    d[1][1] = board[1][1]; //첫번째 b
    d[1][2] = board[1][2]; //첫번째 c
    

    for(int i = 2; i <= n; ++i)
    {
        //현재 선택하는 것이 board[i][k] 임,        
        d[i][0] = min(d[i-1][1], d[i-1][2]) + board[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + board[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + board[i][2];
    }

    cout << *min_element(d[n], d[n]+3);
    

    return 0;
}