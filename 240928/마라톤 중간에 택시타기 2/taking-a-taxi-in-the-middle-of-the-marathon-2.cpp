#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<pair<int,int>> checkPoint;

int main() 
{
    int n;
    cin >> n; 

    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        checkPoint.push_back({a, b});
    }

    int dist = 0;
    int minDist = INT_MAX;
    pair<int, int> before = {checkPoint[0].first, checkPoint[0].second};

    //뺄 것
    for(int i = 1; i < n - 1; ++i)
    {
        for(int j = 1 ; j < n; ++j)
        {
            if(j == i)
                continue;
            dist += (abs(checkPoint[j].first - before.first) + abs(checkPoint[j].second - before.second));
            before = checkPoint[j];
        }
        if(dist < minDist)
            minDist = dist;
    }
    cout << minDist;

    return 0;
}