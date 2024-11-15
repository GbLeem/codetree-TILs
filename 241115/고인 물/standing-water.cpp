#include <iostream>
#include <climits>
#include <queue>
using namespace std;

int n, m;
priority_queue<int, vector<int>, greater<int>> pq;
int answer = 0;

int main()
{
    cin >> n >> m;

    int maxH = INT_MIN;
    for (int i = 0; i < m; ++i)
    {
        int h;
        cin >> h;

        if (maxH == INT_MIN)
            maxH = h;
        else
        {
            //작은 값들 들어올때 
            if (maxH > h)
            {
                pq.push(h);
            }
            //큰 값 만났을때
            else if (maxH <= h)
            {
                //비어있으면 리셋
                if (pq.empty())
                {
                    maxH = h;
                }
                //안비어있으면
                else
                {
                    //마지막인 경우
                    if (i == m - 1 && h < maxH)
                    {
                        while (!pq.empty())
                        {
                            if (pq.top() < h)
                            {
                                answer += (h - pq.top());
                                pq.pop();
                            }
                            else
                                break;
                        }
                    }
                    else
                    {
                        int minH = min(maxH, h);
                        while (!pq.empty())
                        {
                            answer += (minH - pq.top());
                            pq.pop();
                        }
                        maxH = h;
                    }
                }

            }
        }
    }

    cout << answer;
    return 0;
}