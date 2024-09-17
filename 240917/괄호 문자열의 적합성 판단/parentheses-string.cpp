#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> st;

int main() 
{
    string str;
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
                cout<<"No";
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