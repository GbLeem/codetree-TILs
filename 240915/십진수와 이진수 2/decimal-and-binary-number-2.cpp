#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

int main() 
{
    string str;
    cin >> str;

    int num = 0;
    int binary = 0;
    for(int i = str.size() - 1; i >= 0; --i)
    {
        num += pow(2, binary) * (str[i] - '0');
        binary++;
    }

    num *= 17;

    stack<int> s;

    while(1)
    {
        if(num == 1)
            break;
        s.push(num%2);
        num /= 2;
    }
    s.push(1);

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}