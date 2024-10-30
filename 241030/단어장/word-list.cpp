#include <iostream>
#include <map>
#include <string>
using namespace std;

int n;
map<string,int> m;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        m[str]++;
    }

    map<string, int>::iterator it;

    for(it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first <<" " << it->second<<"\n";
    }
    return 0;
}