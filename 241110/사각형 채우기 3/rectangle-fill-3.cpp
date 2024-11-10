#include <iostream>
using namespace std;

int d[1002];

int main() 
{
    int n;
    cin >> n;

    d[1] = 2;
    d[2] = 7;    

    for(int i = 3; i <= n; ++i)
    {
        d[i] = 2*d[i-1] + 4 * d[i-2];
        if(i >= 4)
            d[i] -= (i-3);
    }

    cout << d[n];
    return 0;
}