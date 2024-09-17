#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    stack<int> st;

    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        if(str == "push")
        {
            int num;
            cin >> num;
            st.push(num);
        }
        else if(str == "pop")
        {
            cout << st.top() << "\n";
            st.pop();
        }
        else if(str == "size")
        {
            cout << st.size()<<"\n";
        }
        else if(str == "empty")
        {
            cout << st.empty()<<"\n";
        }
        else if(str == "top")
        {
            cout <<st.top()<<"\n";
        }
    }

    return 0;
}