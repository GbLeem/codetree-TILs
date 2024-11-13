#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int answer = INT_MAX;
vector<pair<int, int>> pos;

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;

        pos.push_back({x, y});
    }

    for(int i = 0; i < n; ++i) //지울 것
    {
        for(int j = 0; j < n; ++j)
        {
            if(i == j)
                continue;
            int distX = abs(pos[i].first - pos[j].first);
            int distY = abs(pos[i].second - pos[j].second);
            answer = min(answer, distX*distX+distY*distY);

        }
    }

    cout << answer;

    return 0;
}