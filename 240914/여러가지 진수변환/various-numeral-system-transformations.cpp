#include <iostream>
using namespace std;

int digits[100000];
int cnt = 0;

void makeB(int n, int B)
{
    while (true) 
    {
        if(n < B) 
        {
            digits[cnt++] = n;
            break;
        }
    
        digits[cnt++] = n % B;
        n /= B;
    }
    
    // print binary number
    for(int i = cnt - 1; i >= 0; i--)
        cout << digits[i];
}

int main() 
{
    int n;
    int b; //4 8

    cin >> n >> b;

    makeB(n, b);
    
    return 0;
}