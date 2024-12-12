#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n, m;
vector<int> vec;
int answer = INT_MAX;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    int en = 0;
    for (int st = 0; st < vec.size(); ++st)
    {
        while (en + 1 < vec.size())
        {
            en++;
            if (vec[en] - vec[st] >= m)
            {
                answer = min(answer, vec[en] - vec[st]);
                break;
            }
        }
        if (vec[en] - vec[st] >= m)
        {
            answer = min(answer, vec[en] - vec[st]);           
        }
    }


    if (answer == INT_MAX)
        cout << -1;
    else
        cout << answer;

    return 0;
}