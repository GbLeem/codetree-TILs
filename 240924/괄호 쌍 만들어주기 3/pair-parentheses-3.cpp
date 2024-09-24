#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str;
    cin >> str;
    bool notOpen = true;
    int answer = 0;

    for(int i = 0; i < str.size(); ++i)
    {
        if(notOpen && str[i] == '(')
        {
            notOpen = false;
            for(int j = i + 1; j < str.size(); ++j)
            {
                if(str[j] == ')')
                    answer++;                
            }
            notOpen = true;
        }
    }

    cout << answer;
    return 0;
}