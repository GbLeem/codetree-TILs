#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

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
                cout << 0 << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }

    return 0;
}