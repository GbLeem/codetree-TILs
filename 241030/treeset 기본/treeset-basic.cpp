#include <iostream>
#include <set>
using namespace std;

set<int> s;
int n;

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        string str;
        int num;
        cin >> str; 

        if(str == "add")
        {
            cin >> num;
            s.insert(num);
        }
        else if(str == "remove")
        {
            cin >> num;
            s.erase(num);
        }
        else if(str =="find")
        {
            cin >> num;
            if(s.find(num)!= s.end())
                cout << "true" <<"\n";
            else 
                cout <<"false"<<"\n";            
        }
        else if(str =="lower_bound")
        {
            cin >> num;
            if(s.lower_bound(num) != s.end())
                cout << *s.lower_bound(num) <<"\n";
            else
                cout <<"None" <<"\n";
        }
        else if(str == "upper_bound")
        {
            cin >> num;
            if(s.upper_bound(num) != s.end())
                cout << *s.upper_bound(num) <<"\n";
            else
                cout <<"None" <<"\n";
        }
        else if(str == "largest")
        {
            if(s.rend() == s.rbegin())
                cout <<"None\n";
            else   
                cout << *s.rbegin() <<"\n";
        }
        else if(str == "smallest")
        {
            if(s.rend() == s.rbegin())
                cout <<"None\n";
            else   
                cout << *s.begin() <<"\n";
        }
    }
    return 0;
}