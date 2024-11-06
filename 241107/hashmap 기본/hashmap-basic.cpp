#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<int, int> um;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        if(str == "add")
        {
            int k,v;
            cin >> k >> v;
            um[k] = v;
        }
        else if(str == "find")
        {
            int num;
            cin >> num;
            //찾으면
            if(um.find(num) != um.end())            
                cout << um[num] << "\n";            
            else
                cout << "None\n";
        }
        else if(str == "remove")
        {
            int num;
            cin >> num;

            um.erase(num);
        }
    }
    return 0;
}