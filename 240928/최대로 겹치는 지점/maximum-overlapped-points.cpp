#include <iostream>
#include <algorithm>
using namespace std;

int board[102];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        for(int j = a; j <= b; ++j)
        {
            board[j]++;
        }
    }
    
    cout << *max_element(board + 1 , board + 102);
    return 0;
}