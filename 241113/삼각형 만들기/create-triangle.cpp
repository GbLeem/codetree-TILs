#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> pos;
int answer = 0;

int getSize(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    int result = 0;
    result = 0.5 * abs((p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) - (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second));

    return result;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        pos.push_back({ x, y });
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                vector<pair<int, int>> l;

                pair<int, int> l1 = { pos[i].first - pos[j].first, pos[i].second - pos[j].second };
                pair<int, int> l2 = { pos[j].first - pos[k].first, pos[j].second - pos[k].second };
                pair<int, int> l3 = { pos[k].first - pos[i].first, pos[k].second - pos[i].second };

                l.push_back(l1);
                l.push_back(l2);
                l.push_back(l3);

                //x좌표 오름, y좌표 오름
                int cnt = 0;
                for (auto li : l)
                {
                    if (li.first == 0 && li.second != 0)
                        cnt++;
                    else if (li.second == 0 && li.first != 0)
                        cnt++;
                }
                if (cnt == 2)
                    answer = max(answer, 2 * getSize(pos[i], pos[j], pos[k]));
            }
        }
    }

    cout << answer;

    return 0;
}