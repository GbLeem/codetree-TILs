#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <unordered_set>
using namespace std;

int n;
vector<tuple<int, int, int>> pos;
unordered_set<int> s;
int answer = 0;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)  
    {
        int a, b;
        cin >> a >> b;
        pos.push_back({a, +1, i});
        pos.push_back({b, -1, i});
    }
    
    sort(pos.begin(), pos.end());

    for(int i = 0; i < 2*n; ++i)
    {
        int x, v, index;
        tie(x, v, index) = pos[i];

        if(v == +1)
        {
            if(s.size() == 0)
                answer++;
            s.insert(index);
        }
        else
        {
            s.erase(index);
        }
    }
    
    cout << answer;

    return 0;
}