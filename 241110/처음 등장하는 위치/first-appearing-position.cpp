#include <iostream>
#include <map>

using namespace std;

int n;
map<int, int> m;

int main() 
{
    cin >> n;
    for(int i = 0; i < n ; ++i)
    {
        int num;
        cin >> num;

        m.insert({num, i + 1});
    }

    for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " " << it->second <<"\n";
    }
    return 0;
}