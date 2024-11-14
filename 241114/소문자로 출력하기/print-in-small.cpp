#include <iostream>
#include <string>
using namespace std;

string str;

int main() 
{
    cin >> str;

    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] >= 'a' && str[i] <= 'z') //97 ~ 
            cout << str[i];
        else if(str[i] >= 'A' && str[i] <= 'Z') //65 ~ 
        {
            char ch = tolower(str[i]);
            cout << ch;
        }
    }    
    return 0;
}