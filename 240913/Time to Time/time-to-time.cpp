#include <iostream>
using namespace std;

int main() 
{
    int a, b, c, d;

    cin >> a >> b >> c >>d;

    int minutes = (60*c + d) - (60 * a + b);

    cout <<  minutes;


    return 0;
}