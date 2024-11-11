#include <iostream>
using namespace std;

int n;
int sum = 0;
int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        sum += num;
    }

    if(sum/n < 70)
        cout << "fail";
    else
    {
        cout << fixed;
        cout.precision(1);
        cout << (float)sum/n;
    }
    return 0;
}