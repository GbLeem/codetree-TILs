#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<string, int> um;
int answer = 0;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        um[str]++;
    }

    for(unordered_map<string, int>::iterator it = um.begin(); it != um.end(); ++it)
    {
        answer = max(answer, it->second);        
    }

    cout << answer;
    return 0;
}