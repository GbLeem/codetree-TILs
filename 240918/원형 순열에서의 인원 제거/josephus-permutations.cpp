#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main() 
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        q.push(i);
    }

    int count = 0;

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        count++;

        if(count == k)
        {
            cout <<temp <<" ";
            count = 0;
        }
        else
            q.push(temp);
        if(q.empty())
            break;
    }


    return 0;
}