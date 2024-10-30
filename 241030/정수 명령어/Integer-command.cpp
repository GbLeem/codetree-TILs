#include <iostream>
#include <set>
using namespace std;

int t, k;

int main() 
{
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        cin >> k;
        set<int> s;
        for(int j = 0; j < k; ++j)
        {
            char str;
            cin >> str;

            if(str == 'I')
            {
                int num;
                cin >> num;
                s.insert(num);
            }
            else if(str == 'D')
            {
                int num;
                cin >> num;

                if(s.rend() == s.rbegin())
                    continue;
                    
                if(num < 0)                
                    s.erase(*s.begin());
                
                else
                    s.erase(*s.rbegin());
            }   
        }

        if(s.rbegin() == s.rend())
            cout <<"EMPTY\n";
        else
            cout << *s.rbegin() << " " << *s.begin() <<"\n";
    }
    return 0;
}