#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
set<int> s;
vector<int> vec;
unordered_map<int, int> um;
int answer = 0;

int main() 
{
    cin >> n >> m;

    for(int i = 1; i <= m; ++i)
    {
        um[i] = 1;
    }
    // 1 2 3 4
    for(int i = 0; i < n; ++i)
    {
        //idx  1 2 3
        //a    4 1 1
        //idx 사람은 1번 이상 a번 이하의 의자에만 앉는다.
        int num;
        cin >> num;
        s.insert(num);
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end()); //1 1 4
    // 1 1 4
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 1; j <= vec[i]; ++j)
        {
            if(um[j] == 1)
            {
                answer++;
                um[j]--;
                break;
            }
        }
    }
    cout << answer;
    // for(auto it = s.begin(); it != s.end(); ++it)
    // {
    //     //4라면
    //     cout <<*it <<"\n";
    //     for(int i = 1; i <= *it; ++i)
    //     {
    //         if(um[i] == 1)
    //         {
    //             answer++;
    //             um[i]--;
    //             break;
    //         }
    //     }
    // }

    //cout << answer;
    return 0;
}