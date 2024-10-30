#include <iostream>
#include <set>
using namespace std;

int n, m;
set<pair<int, int>> s;

int main() 
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        int x, y;        
        cin >> x >> y;
        s.insert({x,y});
    }

    for(int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        
        
        //x보다 크거나 같은        
        if(s.lower_bound(make_pair(x, y)) != s.end())
        {
            pair<int ,int >ans = *s.lower_bound(make_pair(x,y));
            cout << ans.first <<" "<<ans.second<<"\n";
        }
        else
        {
            cout << -1 <<" "<< -1 <<"\n";
        }

    }
    return 0;
}