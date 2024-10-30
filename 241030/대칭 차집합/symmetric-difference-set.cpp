#include <iostream>
#include <unordered_map>
using namespace std;

int a, b;
unordered_map<int, int> um;
int answer = 0;

int main() 
{
    cin >> a >> b;

    for(int i = 0; i < a + b; ++i)    
    {
        int num;
        cin >> num;
        um[num]++;
    }

    for(auto it = um.begin(); it != um.end(); ++it)
    {
        if(it->second == 1)
            answer++;
    }

    cout << answer;

    return 0;
}