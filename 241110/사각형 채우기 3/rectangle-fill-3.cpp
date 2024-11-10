#include <iostream>
using namespace std;

long long d[1002];

int main() 
{
    int n;
    cin >> n;
    d[0] = 1;
    d[1] = 2;
    d[2] = 7;    
    d[3] = 22;

    for(int i = 4; i <= n; ++i)
    {
        d[i] = 2 * d[i - 1]% 1'000'000'007 + 4 * d[i - 2]% 1'000'000'007 - d[i - 4]% 1'000'000'007;
        
    }

    cout << d[n];
    return 0;
}