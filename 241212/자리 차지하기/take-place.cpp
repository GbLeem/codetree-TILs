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

    for (int i = 1; i <= m; ++i)
    {
        s.insert(i); // 1 2 3 4
    }

    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        vec.push_back(num); //4 1 1
    }

    for (int i = 0; i < vec.size(); ++i)
    {
        if (!s.empty())
        {
            //자신보다 같거나 작은 값 없애기
            auto it = s.lower_bound(vec[i]);

            if (it == s.end() || *it > vec[i])
            {
                it--;
            }
            if (it == s.begin())
            {
                if (*it <= vec[i])
                {
                    s.erase(*it);
                    answer++;
                    cout << answer;
                    return 0;
                }                    
                else
                {
                    cout << answer;
                    return 0;
                }
            }
            if (*it <= vec[i])
            {
                s.erase(*it);
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}