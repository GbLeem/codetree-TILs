#include <iostream>
using namespace std;

int d[50];

int main() 
{
    int n;
    cin >> n;

    d[1] = 1;
    d[2] = 1;
    
  
    for(int i = 3; i <= 45; ++i)
    {
        d[i] = d[i-1] + d[i-2]; 
    }
    
    cout << d[n];
    return 0;
}