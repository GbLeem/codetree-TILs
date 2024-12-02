#include <iostream>
#include <cmath>
using namespace std;

float a, b, c;

int main() 
{
    cin >> a >> b >> c;

    int ia, ib,ic;
    ia = round(a); //123
    ib = round(b); //87
    ic = round(c); //22
    

    float answer = 0.f;
    answer = ia + ib + ic;
    cout << answer <<"\n";
    cout << round(answer/3.f);
    return 0;
}