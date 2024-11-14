#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;

vector<int> vec1;
vector<int> vec2;
priority_queue<int, vector<int>, greater<int>> pq3;
priority_queue<int> pq;

int main() 
{
    cin >> n >> m >> k;

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        vec1.push_back(num);
    }

    for(int i = 0; i < m; ++i)
    {
        int num;
        cin >> num;
        vec2.push_back(num);
    }

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    for(int i = 0; i < vec1.size(); ++i)
    {
        int j = 0;
        for(j = 0; j < vec2.size(); ++j)
        {
            pq3.push(vec1[i] + vec2[j]);
            pq.push(vec1[i] + vec2[j]);
        }
        if(!pq.empty() && (pq.top() < (vec1[i] + vec2[j + 1])))
            break;
    }    
    while(k > 1)
    {
        //cout << pq3.top()<<"\n";
        pq3.pop();
        k--;
    }
    cout << pq3.top();
    return 0;
}