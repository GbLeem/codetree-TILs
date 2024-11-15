#include <iostream>
#include <stack>
#include <climits>
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

        if (tempH == -1)
        {
            tempH = h;
        }
        else //두번째 부터
        {
            if (i == m - 1)
            {
                if (!s.empty())
                {
                    int minH = min(h, tempH);
                    while (!s.empty())
                    {
                        answer += (minH - s.top());
                        s.pop();
                    }
                }
            }
            //작은 높이 
            else if (tempH > h)
            {
                s.push(h);
            }
            //큰 높이
            else
            {
                if (s.empty())
                    tempH = h;                    
                else
                {                
                    if (s.top() < h)
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
        }
    }
    cout << answer;
    return 0;
}