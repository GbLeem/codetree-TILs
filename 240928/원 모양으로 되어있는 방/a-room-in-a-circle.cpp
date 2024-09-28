#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int board[1005];

int main() 
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i + 1]; // 0 4 7 8 6 4
    }

    int minDist = INT_MAX;
    //시작점 선택
    for(int i = 1; i <= n; ++i)
    {
        int dist = 0;
        for(int j = i; j < i + n; ++j)
        {   
            int index = j;
            if(index > n)
                index %= n;
            dist += abs(j - i) * board[index];
        }

        if(minDist > dist)
            minDist = dist;
    }
    cout << minDist;

    return 0;
}