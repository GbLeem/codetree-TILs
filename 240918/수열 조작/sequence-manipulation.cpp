#include <iostream>
#include <deque>
using namespace std;

deque<int>dq;

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        dq.push_back(i+1);
    }

    while(1)
    {
        if(dq.size() == 1)
        {
            cout <<dq.back();
            break;
        }

        dq.pop_front();
        int temp = dq.front();
        dq.pop_front();
        dq.push_back(temp);
    }

    return 0;
}