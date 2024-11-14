#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;
int answer = 0;
int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }    

    sort(v.begin(), v.end());
    
    for(int i = 1; i <= n; ++i)
    {
        answer += v[i-1] * (n - i + 1); 
    }

    cout << answer;
    return 0;
}