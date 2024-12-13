#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N, K, P, T;
vector<tuple<int, int, int>> vec;
unordered_map<int, int> um; //감염된 사람 넣기

int main() 
{
    cin >> N >> K >> P >> T; //4 2 2 3

    //감염된 사람 체크
    for(int i = 1; i <= N; ++i)
    {
        um[i] = 0;
    }
    um[P] = 1;

    for(int i = 0; i < T; ++i)
    {
        int t, x, y;
        cin >> t >> x >> y;

        vec.push_back({t,x,y});
    }    

    //시간대로 정렬
    sort(vec.begin(), vec.end()); 
    
    //5 2 3
    //6 2 4
    //7 1 2

    for(int i = 0; i < vec.size(); ++i)
    {
        //감염된 놈일 때
        int x = get<1>(vec[i]);
        int y = get<2>(vec[i]);

        if(um[x] == 1)
        {
            um[y] = 1;
            K--;
        }
        else if(um[y] == 1)
        {
            um[x] = 1;
            K--;
        }

        if(K == 0)
            break;
    }
    
    
    for(int i = 1; i <= N; ++i)
    {
        cout << um[i];
    }

    return 0;
}