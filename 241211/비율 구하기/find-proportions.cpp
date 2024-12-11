#include <iostream>
#include <map>
using namespace std;

int n;
map<string, int> m;

int main() 
{
    cin >> n;
    
    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        m[str]++;
    }
    cout<<fixed;
    cout.precision(4);

    for(auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " " << (float)it->second/n *100.f<<"\n";
    }
    return 0;
}