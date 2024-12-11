#include <iostream>
#include <unordered_set>
using namespace std;

int n;
unordered_set<int> us;

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        if(str == "find")
        {
            int num;
            cin >> num;

            if(us.find(num) != us.end())
                cout << "true\n";
            else
                cout <<"false\n";
        }
        else if("add")
        {
            int num;
            cin >> num;

            us.insert(num);
        }
        else if("remove")
        {
            int num;
            cin >> num;
            
            us.erase(num);
        }
    }
    return 0;
}