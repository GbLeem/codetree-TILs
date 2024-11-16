#include <iostream>
#include <queue>
using namespace std;

int n, m;
priority_queue<int> pq;

int main() 
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        pq.push(num);
    }    

    while(m--)
    {
        int maxValue = pq.top();
        pq.pop();
        pq.push(maxValue - 1);
    }

    cout << pq.top();

    return 0;
}