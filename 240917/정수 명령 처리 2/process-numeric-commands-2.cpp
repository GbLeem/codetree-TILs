#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<int> q;

int main() 
{   
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        if(str == "push")
        {
            int num; 
            cin >> num;
            q.push(num);
        }
        else if(str == "pop")
        {
            cout << q.front()<<"\n";
            q.pop();
        }
        else if(str == "size")
        {
            cout << q.size() <<"\n";
        }
        else if(str == "empty")
        {
            cout <<q.empty() << "\n";
        }
        else if(str == "front")
        {
            cout << q.front()<<"\n";
        }
    }
    return 0;
}