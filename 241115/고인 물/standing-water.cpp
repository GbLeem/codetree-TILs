#include <iostream>
#include <climits>
#include <stack>
using namespace std;

int n, m;
stack<int> s;
unsigned long answer = 0;
int board[505];

int main()
{
    cin >> n >> m;

    int maxH = INT_MIN;
    for (int i = 0; i < m; ++i)
    {
        cin >> board[i];
    }

    for(int i = 0; i < m; ++i)
    {       
        int h = board[i];
        if (maxH == INT_MIN)
            maxH = h;
        else
        {
            //마지막인 경우
            if (i == m - 1)
            {
                while (!s.empty())
                {
                    while(s.top() < h)
                    {
                        answer += (h - s.top());
                        s.pop();
                    }
                    h = s.top();
                }

            }
            //작은 값들 들어올때 
            else if (maxH > h)
            {
                s.push(h);
            }
            //큰 값 만났을때
            else if (maxH <= h)
            {
                //비어있으면 리셋
                if (s.empty())
                {
                    maxH = h;
                }
                //안비어있으면
                else
                {                                    
                    int minH = min(maxH, h);
                    while (!s.empty())
                    {
                        answer += (minH - s.top());
                        s.pop();
                    }
                    maxH = h;                    
                }
            }
        }
    }

    cout << answer;
    return 0;
}