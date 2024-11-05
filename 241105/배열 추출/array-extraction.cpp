#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> pq;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int n;
        cin >> n;
        if(n == 0)
        {
            if(pq.empty())
            {
                cout << 0 <<"\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
            pq.push(n);
    }
    return 0;
}