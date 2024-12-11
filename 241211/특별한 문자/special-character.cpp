#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> um;


int main() 
{   
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); ++i)
    {
        um[str[i]]++;
    }

    for(int i = 0; i < str.size(); ++i)
    {
        if(um[str[i]] == 1)
        {
            cout << str[i];
            return 0;
        }
    }

    cout << "None";
    return 0;
}