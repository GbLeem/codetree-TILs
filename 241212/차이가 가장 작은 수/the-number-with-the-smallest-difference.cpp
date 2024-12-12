#include <iostream>
#include <set>
#include <climits>
using namespace std;

int n, m;
set<int> s;
int answer = INT_MAX;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        s.insert(num);
    }

    //1 3 5
    //차이는 3이상

    bool find = false;

    auto en = s.begin();

    for (auto st = s.begin(); st != s.end(); ++st)
    {
        while (en != s.end())
        {
            en++;
            if (en == s.end())
                break;
            if (*en - *st >= m)
            {
                answer = min(answer, *en - *st);
                break;
            }
        }
    }
    if(answer == INT_MAX)
        cout << -1;
    else
        cout << answer; 

    return 0;
}