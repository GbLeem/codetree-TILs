#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
unordered_set<int> us;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        us.insert(num);
    }

    cin >> m;

    for(int i = 0; i < m; ++i)
    {
        int num;
        cin >> num;
        if(us.find(num) != us.end())
            cout <<1<<"\n";
        else
            cout <<0<<"\n";
    }
    return 0;
}