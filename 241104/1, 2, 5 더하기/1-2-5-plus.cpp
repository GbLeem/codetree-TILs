#include <iostream>
using namespace std;

int n;
int d[1002];
int board[3] = {1 ,2, 5};

int main() 
{
    cin >> n;

    d[0] = 1; // 자기 자신
    d[1] = 1; // 1
    d[2] = 2; // 1 + 1, 2
    
    //d[i] 만들기
    for(int i = 3; i <= n; ++i)
    {
        //현재 고른 숫자 인덱스가 j라면
        for(int j = 0; j <= 2; ++j)
        {
            if(i - board[j] >= 0)
            {
                d[i] += d[i - board[j]];
                //cout << i << " " << j << " " << d[i]<<"\n";
            }
        }
    }    

    cout << d[n];
    return 0;
}