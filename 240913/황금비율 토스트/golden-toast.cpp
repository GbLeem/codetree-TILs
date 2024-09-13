#include <iostream>
#include <list>
using namespace std;

int main() 
{
    list<char> ll;    

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        ll.push_back(c);
    }

    list<char>::iterator it = ll.end();
    
    for(int i = 0; i < m; ++i)
    {
        char query;
        cin >> query;

        if(query == 'L')
        {
            if(it != ll.begin())
                --it;
        }
        else if(query == 'R')
        {
            if(it != ll.end())
                ++it;
        }
        else if(query == 'P')
        {
            char ch;
            cin >> ch;

            ll.insert(it, ch);
        }
        else if(query == 'D')
        {
            if(it != ll.end())
                ll.erase(it);
        }
    }

    for(list<char>::iterator i = ll.begin(); i != ll.end(); ++i)
    {
        cout << *i;
    }
    
    

    return 0;
}