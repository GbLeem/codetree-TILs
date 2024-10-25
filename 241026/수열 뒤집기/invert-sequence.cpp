#include <iostream>
using namespace std;

int n, k;
int a1, a2;
int b1, b2;
int board[102];


void Change(int st, int en)
{
    int cnt = (en - st + 1)/2;

    for(int i = 0; i < cnt; ++i)
    {
        swap(board[st], board[en]);
        st+=1;
        en-=1;
    }
}

int main() 
{
    cin >> n >> k;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    for(int i = 1; i <= n; ++i)
    {
        board[i] = i;
    }

    for(int i = 0; i < k; ++i)
    {
        Change(a1, a2);
        Change(b1, b2);
    }

    for(int i = 1; i <= n; ++i)
    {
        cout << board[i] <<"\n";
    }

    return 0;
}