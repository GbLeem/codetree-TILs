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

    //뺄 것
    int minDist = INT_MAX;
    
    for(int i = 1; i < n - 1; ++i) // 1 2
    {
        int dist = 0;
        pair<int, int> before = {checkPoint[0].first, checkPoint[0].second};
        for(int j = 1 ; j < n; ++j) // 1 2 3 
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