#include <iostream>
using namespace std;

int n, k;
int a1, a2;
int b1, b2;
int board[102];

void Change(int st, int en)
{
    int tempBoard[102];
    int end = en;

    for(int i = st; i <= en; ++i)
    {
        tempBoard[i] = board[end];
        end--;
    }
    for(int i = st; i <= en; ++i)
    {
        board[i] = tempBoard[i];
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
    //O^(k*(en-st+1)/2)
    //k가 10억
    for(int i = 0; i < k; ++i)
    {
        Change(a1, a2);
        Change(b1, b2);
    }

    //print
    for(int i = 1; i <= n; ++i)
    {
        cout << board[i] <<"\n";
    }

    return 0;
}