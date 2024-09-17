#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() 
{
    string str;
    stack<char> st;
    cin >> str;

    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == '(')
        {
            st.push('(');
        }
        else // )인 경우
        {
            if(st.top() == '(')
            {
                st.pop();
            }            
            else
            {
                cout <<"No";
                return 0;
            }
        }
    }
    if(st.empty())
        cout <<"Yes";
    else
        cout <<"No";
    return 0;
}