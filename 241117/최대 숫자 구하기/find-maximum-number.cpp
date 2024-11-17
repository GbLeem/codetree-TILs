#include <iostream>
#include <set>
using namespace std;

int n, m;
set<int> s;

int main() 
{
    cin >> n >> m;

    for(int i = 1; i <= m; ++i)
    {
        s.insert(i);
    }

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;

        s.erase(num);
        cout << *s.rbegin() <<"\n";
    }



    return 0;
}