#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<int, int> um;
vector<pair<int,int>> vec;
int n, k;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

int main() 
{
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        um[num]++;
    }

    for(auto it = um.begin(); it != um.end(); ++it)
    {
        vec.push_back({it->second, it->first});
    }

    sort(vec.begin(), vec.end(), cmp);

    for(int i = 0; i < k; ++i)
    {
        cout << vec[i].second<<" ";
    }
    return 0;
}