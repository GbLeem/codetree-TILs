#include <iostream>
#include <set>
using namespace std;

int n, k;
set<int> s;

int main() 
{
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        s.insert(-num);
    }

    auto it = s.begin();
    for(int i = 0; i < k; ++i)
    {
        cout << -*it << " ";
        it++;
    }

    return 0;
}