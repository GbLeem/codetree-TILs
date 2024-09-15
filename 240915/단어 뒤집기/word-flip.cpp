#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

stack<char> reverseStr;
queue<char> normalStr;
int main() 
{
    string str;
    getline(cin, str);

    bool rev = true;
    bool going = false;

    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == '<')
        {
            going = true;
            rev = false;
            normalStr.push('<');

            if(!reverseStr.empty())
            {
                while(!reverseStr.empty())
                {
                    cout << reverseStr.top();
                    reverseStr.pop();
                }
            }
        }
        else if(str[i] == '>')
        {
            going = false;
            rev = true;
            normalStr.push('>');

            while(!normalStr.empty())
            {
                cout << normalStr.front();
                normalStr.pop();
            }
        }
        else if(str[i] == ' ' && !going)
        {
            while(!reverseStr.empty())
            {
                cout << reverseStr.top();
                reverseStr.pop();
            }
            cout << " ";
        }
        else //그냥 글자인 경우
        {
            if(rev)
                reverseStr.push(str[i]);
            else
                normalStr.push(str[i]);
        }
    }

    //마지막
    if(!reverseStr.empty())
    {
        while(!reverseStr.empty())
        {
            cout << reverseStr.top();
            reverseStr.pop();
        }
    }
    if(!normalStr.empty())
    {
        while(!normalStr.empty())
        {
            cout << normalStr.front();
            normalStr.pop();
        }
    }

    return 0;
}