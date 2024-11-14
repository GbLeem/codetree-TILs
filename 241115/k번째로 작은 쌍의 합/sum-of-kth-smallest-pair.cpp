#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;

vector<int> vec1;
vector<int> vec2;
priority_queue<int> pq3;

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        vec1.push_back(num);
    }

    for (int i = 0; i < m; ++i)
    {
        int num;
        cin >> num;
        vec2.push_back(num);
    }

    sort(vec1.begin(), vec1.end(), greater<int>()); // 7 6 3 2 1
    sort(vec2.begin(), vec2.end(), greater<int>()); // 8 7 5 1

    for (int i = 0; i < vec1.size(); ++i)
    {
        for (int j = 0; j < vec2.size(); ++j)
        {
            pq3.push(vec1[i] + vec2[j]);
        }
        if (pq3.size() > 2 * k)
        {
            while (pq3.size() > 2 * k)
            {
                pq3.pop();
            }
        }
    }

    int size = pq3.size();
    size -= k;
    while (size > 0)
    {
        //cout << pq3.top()<<"\n";
        pq3.pop();
        size--;
    }
    cout << pq3.top();
    return 0;
}