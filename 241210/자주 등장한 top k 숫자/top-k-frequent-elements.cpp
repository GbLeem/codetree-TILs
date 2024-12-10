#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<int, int> um;
unordered_multimap<int, int> umm;
int n, k;

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        um[num]++;
    }

    int idx = 0;
    vector<int> cost;

    for (auto it = um.begin(); it != um.end(); ++it)
    {
        umm.insert({it->second, it->first}); // 갯수 값
        cost.push_back(it->second); //갯수
    }

    sort(cost.begin(), cost.end(), greater<int>());

    for (int i = 0; i < cost.size(); ++i) //2 2 1
    {
        auto range = umm.equal_range(cost[i]);

        vector<int> temp;
        int s = 0;
        for(auto it = range.first; it != range.second; ++it)
        {
            temp.push_back(it->second);                           
            k--;  
            s++;
        }
        i += s - 1;

        if (temp.size() > 1)
        {
            sort(temp.begin(), temp.end(), greater<int>());
            for (auto t : temp)
                cout << t << " ";
        }
        else
            cout << temp.back() << " ";

        if (k == 0)
            break;
    }


    return 0;
}