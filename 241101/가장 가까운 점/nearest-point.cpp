#include <iostream>
#include <queue>
using namespace std;

int n, m;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if(a.first + a.second == b.first + b.second)
        {   
            if(a.first == b.first)
            {
                return a.second < b.second;
            }
            return a.first < b.first;
        }
        return a.first +a.second > b.first + b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main() 
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        pq.push({x, y});
    }

    for(int i = 0; i < m; ++i)
    {
        int x = pq.top().first;
        int y = pq.top().second;
        //cout << x << " "<<y<<"\n";
        pq.pop();
        pair<int, int> p = {x + 2, y + 2};
        pq.push(p);
    }

    cout << pq.top().first << " "<<pq.top().second;
    return 0;
}