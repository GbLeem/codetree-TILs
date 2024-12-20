#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

int N, K, P, T;
vector<tuple<int, int, int>> vec;
unordered_map<int, int> um; //감염횟수
int people[102]; //감염된 사람

int main() 
{
    cin >> N >> K >> P >> T; //4 2 2 3

    //감염된 사람 체크
    for(int i = 1; i <= N; ++i)
    {
        um[i] = INT_MIN;
    }
    um[P] = K;
    people[P] = 1;

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

        //y가 새롭게 감염
        if(um[x] > 0 && um[y] == INT_MIN)
        {
            um[y] = K;
            people[y] = 1;
            um[x]--;
        }
        //x가 새롭게 감염
        else if (um[x] == INT_MIN && um[y] > 0)
        {
            um[x] = K;
            people[x] = 1;
            um[y]--;
        }

        //둘다 이미 감염 혹은 감염 끝
        else if(um[x] > INT_MIN && um[y] > INT_MIN)
        {
            um[x]--;
            um[y]--;
            people[x] = 1;
            people[y] = 1;
        }

        bool check = true;
        for(int j = 1; j <= N; ++j)
        {
            if(um[j] > 0)
                check = false;
        }       
        //모든 횟수를 다 쓴 경우
        if(check)
            break;
    }
    
    
    for(int i = 1; i <= N; ++i)
    {
        cout << people[i];
    }

    return 0;
}