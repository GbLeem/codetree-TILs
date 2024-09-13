#include <iostream>
using namespace std;

int main() 
{
    int m1, m2;
    int d1, d2;
    int elapsedTime = 0;
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    cin >> m1 >> d1 >> m2 >> d2;

    while(1)
    {
        if(m1 == m2 && d1 == d2)
            break;

        elapsedTime++;
        d1++;

        if(d1 > days[m1])
        {
            m1++;
            d1 = 0;
        }        
    }
    cout << elapsedTime;

    return 0;
}