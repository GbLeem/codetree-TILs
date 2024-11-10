#include <iostream>
#include <map>
using namespace std;

int n;

int main() 
{
    cin >> n;
    map<int, int> m;

    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        if(str == "add")
        {
            int k, v;
            cin >> k >> v;
            m[k] = v;
        }
        else if(str == "remove")
        {
            int k;
            cin >> k;
            m.erase(k);
        }
        else if(str == "find")
        {
            int k;
            cin >> k;
            if(m.find(k) == m.end())
                cout << "None\n";
            else
                cout << m[k] << "\n";
        }
        else if(str == "print_list")
        {
            if(m.empty())
                cout <<"None\n";
            else
            {
                for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
                {
                    cout << it->second <<" ";
                }
                cout <<"\n";
            }
        }
    }
    
    return 0;
}