#include <iostream>
#include <queue>
using namespace std;

int t, m;

int main() 
{
    cin >> t;

    while(t--)
    {
        cin >> m;

        int mid = -1;
        priority_queue<int> smallpq;
        priority_queue<int, vector<int>, greater<int>> bigpq;

        for(int i = 1; i <= m; ++i)
        {
            int num; 
            cin >> num;

            //맨 처음
            if(mid == -1)
                mid = num;
            else if(num < mid)
            {
                smallpq.push(num);
            }
            else if(num >= mid)
            {
                bigpq.push(num);
            }
        
            if(i % 2 != 0)
            {
                //비대칭일 때
                if(!bigpq.empty() && smallpq.size() < bigpq.size())
                {
                    smallpq.push(mid);
                    mid = bigpq.top();
                    bigpq.pop();
                }
                else if(!smallpq.empty() && smallpq.size() > bigpq.size())
                {
                    bigpq.push(mid);
                    mid = smallpq.top();
                    smallpq.pop();
                }

                cout << mid <<" ";
            }            
        }
        cout<<"\n";
    }    
    return 0;

}