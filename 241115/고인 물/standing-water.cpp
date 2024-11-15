#include <iostream>
#include <stack>
using namespace std;

int n, m;
stack<int> s;
int answer = 0;

int main() 
{
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int h;
        cin >> h;

        if(s.empty())
            s.push(h);
        else
        {
            if(s.top() > h && i != m-1)
            {
                answer += (s.top() - h);                
            }
            else if(s.top() <= h)
            {
                s.pop();
                s.push(h);
            }
        }
    }
    cout << answer;
    return 0;
}