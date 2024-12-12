#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> vec;
set<pair<int, int>> s;

int main() 
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        s.insert({x, y});
    }

    for(int i = 0; i < m; ++i)
    {
        int k; 
        cin >> k;

        auto it = s.lower_bound({k, -1});

        if(it == s.end())
        {
            cout << -1 <<" "<< -1<<"\n";
        }
        else
        {
            cout <<it->first <<" "<<it->second <<"\n";
            s.erase({it->first, it->second});
        }
    }

    return 0;
}