#include <iostream>
using namespace std;

int n;
long long M = 2'000'000'000;

int main() 
{
    cin >> n;
    
    for(int i = 1; i <= M; ++i)
    {
        if(i % 3 != 0 && i % 5 != 0)
            n--;
        if(n == 0)
        {
            cout << i;
            break;
        }
    }

    return 0;
}