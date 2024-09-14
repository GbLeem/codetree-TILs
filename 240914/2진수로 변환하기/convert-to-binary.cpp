#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main() 
{
    int n;
    cin >> n;

    s.push(1);
    while(1)
    {
        if(n == 1)
            break;
        s.push(n % 2);
        n/=2;        
    }    

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}