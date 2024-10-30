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

        pq.push(num);

        if(pq.size() >= 3)
        {
            int value = 1;
            int cnt = 3;
            queue<int> temp;
            while(cnt > 0)
            {
                value *= pq.top();
                temp.push(pq.top());
                pq.pop();
                cnt--;
            }    
            cout << value <<"\n";

            while(!temp.empty())
            {
                pq.push(temp.front());
                temp.pop();
            }
        }
        else
            cout << -1 <<"\n";
    }
    

    return 0;
}