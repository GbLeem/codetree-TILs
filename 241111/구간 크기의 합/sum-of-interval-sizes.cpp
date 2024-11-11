#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n;
vector<pair<int, int>> pos;
set<int> s;
int answer = 0;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;

        pos.push_back({a, 1});
        pos.push_back({b, -1});
    }

    sort(pos.begin(), pos.end());

    int start = 0;
    int temp = 0;

    for(int i = 0; i < 2*n; ++i)
    {
        if(pos[i].second == 1)
        {                        
            if(start == 0)    
                start = pos[i].first;
            temp++;
        }
        else if(pos[i].second == -1)
        {
            temp--;

            if(temp == 0)
            {
                answer += (pos[i].first - start);
                start = 0;
            }
        }
    }

    cout << answer;
    return 0;
}