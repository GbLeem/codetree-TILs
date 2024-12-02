#include <iostream>
using namespace std;

int n;
int answer = 0;
int cnt = 0;

int main() 
{
    cin >> n;
    answer = n;

    while(1)
    {        
        int ten  = (answer / 10) % 10;
        int zero = answer % 10;
        
        answer = 10 * zero + (ten+zero) % 10;
        cnt++;

        if(answer == n)
            break;
    }
    cout << cnt;
    return 0;
}