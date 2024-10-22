#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> vec;
int d[1002]; //i번째 왔을때 최대 길이

bool cmp(pair<int, int> v1, pair<int, int> v2)
{
    if(v1.first == v2.first)
        return v1.second < v2.second;
    return v1.first < v2.first;
}

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int x1, x2;
        cin >> x1 >> x2;
        vec.push_back({x1, x2});
    }

    sort(vec.begin(), vec.end(), cmp);

    for(int i = 0; i < n; ++i)
        d[i] = 1;

    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            //i+1 번째를 선택했을 때
            if(vec[i].first > vec[j].second)
            {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }    
    // for(int i = 0; i < n; ++i)
    //     cout << d[i] << "\n";

    cout << *max_element(d, d + n);
    return 0;
}