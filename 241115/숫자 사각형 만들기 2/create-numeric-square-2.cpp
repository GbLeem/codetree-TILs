#include <iostream>
using namespace std;

int n, m;

int main() 
{
    cin >> n >> m;
    int value = n*m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << value-- <<" ";
        }
        cout << "\n";
    }
    return 0;
}