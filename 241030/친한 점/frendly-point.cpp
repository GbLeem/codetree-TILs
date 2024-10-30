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
        pair<int, int> comp = {x, y};        
        pair<int, int> ans;
        //x보다 크거나 같은
        if(lower_bound(s.begin(), s.end(), comp) != s.end())
        {
            ans = *lower_bound(s.begin(), s.end(), comp);
        }
        else
        {
            ans.first = -1;
            ans.second = -1;
        }

        cout << ans.first <<" "<<ans.second <<"\n";
    }
    return 0;
}