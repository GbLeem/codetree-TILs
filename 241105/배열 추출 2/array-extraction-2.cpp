#include <iostream>
#include <queue>
using namespace std;

int n;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;

        if(num == 0)
        {
            if(pq.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << pq.top().second <<"\n";
                pq.pop();
            }
        }
        else
            pq.push({abs(num), num});
    }
    return 0;
}