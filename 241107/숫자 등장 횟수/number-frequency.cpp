#include <iostream>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map<int, int> um;

int main() 
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        um[num]++;
    }

    for(int i = 0; i < m; ++i)
    {
        int query;
        cin >> query;

        cout << um[query]<<" ";
    }
    return 0;
}