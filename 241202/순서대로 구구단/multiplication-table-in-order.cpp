#include <iostream>
using namespace std;

int a, b;

int main() 
{
    cin >> a >> b;

    if(a > b)
    {        
        for(int j = 1; j <= 9; ++j)
        {
            for(int i = a; i >= b; --i)
            {
                cout << i <<" * " << j << " = "<< i * j <<"  ";
            }
            cout << "\n";
        }
    }    
    else
    {
        for(int j = 1; j <= 9; ++j)
        {
            for(int i = a; i <= b; ++i)
            {
                cout << i <<" * " << j << " = "<<i*j<<"  ";
            }
            cout << "\n";
        }
    }
    return 0;
}