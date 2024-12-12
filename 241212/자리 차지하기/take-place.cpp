#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
set<int> s;
vector<int> vec;
int answer = 0;

int main() 
{
    cin >> n >> m;

    for(int i = 1; i <= m; ++i)
    {
        s.insert(i);
    }
    // 1 2 3 4
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end()); //1 1 4

    // 1 1 4
    for(int i = 0; i < vec.size(); ++i)
    {
        if(!s.empty())
        {
            if(*s.begin() <= vec[i])
            {
                s.erase(*s.begin());
                answer++;
            }
            else
                break;
        }
    }

    cout << answer;
        
    return 0;
}