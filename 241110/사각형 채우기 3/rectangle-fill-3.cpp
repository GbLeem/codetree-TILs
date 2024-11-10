#include <iostream>
using namespace std;

int MOD = 1'000'000'007;
int d[1002];

int main()
{
    int n;
    cin >> n;
    d[0] = 1;
    d[1] = 2;
    d[2] = 7;
    d[3] = 22;

    for (int i = 4; i <= n; ++i)
    {
        d[i] = (2LL * d[i - 1] + 4LL * d[i - 2] - d[i - 4]) % MOD;
        if (d[i] < 0) 
            d[i] += MOD;  // 음수인 경우 보정
    }

    cout << d[n];
    return 0;
}