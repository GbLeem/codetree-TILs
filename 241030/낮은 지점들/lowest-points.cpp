#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<int, int> um;

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;

        if(um.find(x) == um.end())
        {
            um[x] = y;
        }
        else if(um.find(x) != um.end()) //찾으면
        {
            if(um[x] > y) //새로운 y값이 제일 작으면
            {
                um[x] = y;
            }
        }
    }

    unordered_map<int, int>::iterator it;

    int answer = 0;
    for(it = um.begin(); it != um.end(); ++it)
    {
        answer += it->second;
        //cout << it->second <<"\n";
    }

    cout << answer;
    return 0;
}