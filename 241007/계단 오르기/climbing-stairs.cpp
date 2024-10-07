#include <iostream>
using namespace std;

int d[1002];

int main() 
{
    int n; 
    cin >> n;

    d[1] = 0;
    d[2] = 1;
    d[3] = 1;
    d[4] = d[1] + d[2];
    
    for(int i = 4; i <= n; ++i)
    {
        d[i] = d[i-2] + d[i-3];
    }

    cout << d[n];

    return 0;
}