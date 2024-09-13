#include <iostream>
using namespace std;

int main() 
{
    int a, b, c; //일 시 분    
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    cin >> a >> b >> c;
    int minutes = (a * 24 * 60 + b * 60 + c) - (11 * 24 * 60 + 11* 60 + 11);

    if(minutes < 0)
        cout << -1;
    else
        cout <<  minutes;


    return 0;
}