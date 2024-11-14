#include <iostream>
using namespace std;

int main() 
{
    int x1, x2, x3, x4;    
    cin >> x1 >> x2 >> x3 >> x4;

    if(x1 < x3)
    {
        if(x2 >= x3)
            cout <<"intersecting\n";
        else
            cout <<"nonintersecting";

    }
    else
    {
        if(x4 >= x1)
            cout <<"intersecting\n";
        else
            cout <<"nonintersecting";
    }
    return 0;
}