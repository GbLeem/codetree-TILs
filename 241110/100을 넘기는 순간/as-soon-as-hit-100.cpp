#include <iostream>
using namespace std;

int n;
int board[55];

int main() 
{
    cin >> n;
    int sum = 0;
    int cnt = 0;

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        sum += num;
        cnt++;
        if(num >= 100)
        {
            cout << fixed;
            cout.precision(1);
            cout << sum <<"\n" << (float)sum/cnt;
        }
    }
    return 0;
}