#include <iostream>
using namespace std;

int board[200002];

int main() 
{
    int n;
    int max_x2 = -1;

    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int x1, x2;
        cin >> x1 >> x2;
    
        if(max_x2 < x2)
            max_x2 = x2;

        board[x1] += 1;
        board[x2] -= 1;        
    }
    
    int sum = 0;
    int max_sum = 0;

    for(int i = 1; i <= max_x2; ++i)
    {
        sum += board[i];
        if(max_sum < sum)
            max_sum = sum;
    }
    cout << max_sum;
    return 0;
}