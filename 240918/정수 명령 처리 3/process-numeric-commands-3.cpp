#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

int main() 
{
    int n;
    cin >>n;

    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        if(str == "push_front")
        {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if(str == "push_back")
        {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if(str == "pop_front")
        {
            cout << dq.front() <<"\n";
            dq.pop_front();
        }
        else if(str == "pop_back")
        {
            cout << dq.back() <<"\n";
            dq.pop_back();
        }
        else if(str == "size")
        {
            cout << dq.size() <<"\n";
        }
        else if(str == "empty")
        {
            cout << dq.empty()<<"\n";
        }
        else if(str =="front")
        {
            cout <<dq.front() <<"\n";
        }
        else if(str == "back")
        {
            cout <<dq.back() <<"\n";
        }
    }
    return 0;
}