#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> pos;
int answer = 0;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x1, x2;
        cin >> x1 >> x2;
        pos.push_back({x1, +1});
        pos.push_back({x2, -1});
    }

    sort(pos.begin(), pos.end());


    int tempSum = 0;
    for(int i = 0; i < 2 * n; ++i)
    {
        tempSum += pos[i].second;

        answer = max(answer, tempSum);
    }
    cout << answer;
    return 0;
}