#include <iostream>
using namespace std;

int n;

int main() 
{
    cin >> n;

    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - i; ++j)
            cout << "**";
        cout <<"\n";
    }
    cout << "**\n";
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 0; j < i; ++j)        
            cout << "**";
        cout << "\n";
    }
    return 0;
}