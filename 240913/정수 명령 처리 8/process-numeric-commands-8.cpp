#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    list<int> ll;

    while(n--)
    {
        string str;
        int num;
        cin >> str;

        if(str == "push_front")
        {
            cin >> num;
            ll.push_front(num);
        }
        else if(str == "push_back")
        {
            cin >> num;
            ll.push_back(num); 
        }
        else if(str == "pop_front")
        {
            cout << ll.front() << "\n";
            ll.pop_front();
        }
        else if(str == "pop_back")
        {
            cout << ll.back() << "\n";
            ll.pop_back();
        }
        else if(str == "size")
        {
            cout << ll.size() << "\n";
        }
        else if(str == "empty")
        {
            cout << ll.empty() << "\n";
        }
        else if(str == "front")
        {
            cout << ll.front() << "\n";
        }
        else if(str == "back")
        {
            cout << ll.back() << "\n";
        }
    }

    return 0;
}