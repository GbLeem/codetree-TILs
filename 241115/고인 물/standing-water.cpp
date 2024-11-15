#include <iostream>
#include <stack>
using namespace std;

int n, m;
stack<int> s;
int answer = 0;

int main()
{
    cin >> n >> m;

    int tempH = -1;

    for (int i = 0; i < m; ++i)
    {
        int h;

        cin >> h;

        if (s.empty()) 
        {
            if (tempH == -1)
                tempH = h;
            else
            {
                if (tempH > h)
                {
                    s.push(h);
                }
                else
                    tempH = h;
            }
        }
        //비어있지 않을 때 (물이 고임)
        else
        {   
            //맨 마지막
            if (i == m - 1)
            {
                if (!s.empty() && s.top() < h)
                {
                    int minH = min(h, tempH);
                    while (!s.empty())
                    {
                        answer += (minH - s.top());
                        s.pop();
                    }
                }
            }
            else if (tempH > h)
                s.push(h);
            //물보다 높은 벽
            else if (s.top() < h)
            {
                int minH = min(h, tempH);
                while (!s.empty())
                {
                    answer += (minH - s.top());
                    s.pop();
                }
                tempH = h;
            }            
        }

    }
    cout << answer;
    return 0;
}