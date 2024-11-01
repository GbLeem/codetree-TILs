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
        int num;
        cin >> num;
        pq.push(num);
    }    
    
    while(1)
    {
        if(pq.size() >= 2)
        {
            int n1 = pq.top();
            pq.pop();
            int n2 = pq.top();
            pq.pop();

            int n3 = n1 - n2;
            if(n3 != 0)
                pq.push(n3);
        }        
        if(pq.size() == 1)
        {
            cout << pq.top();
            return 0;
        }
        if(pq.empty())
        {
            cout << -1;
            return 0;
        }
    }
    return 0;
}