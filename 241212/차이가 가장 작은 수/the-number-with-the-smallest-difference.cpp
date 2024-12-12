#include <iostream>
#include <set>
#include <climits>
using namespace std;

int n, m;
set<int> s;
int answer = INT_MAX;

int main() 
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        s.insert(num);
    }

    //1 3 5
    //차이는 3이상

    for(auto it = s.begin(); it != s.end(); ++it)
    {
        auto big = s.upper_bound(*it); //*it 보다 큰 수
        
        while(big != s.end())
        {
            bool find = false;

            if(*big - *it >= m)
            {
                answer = min(answer, *big - *it);
                find = true;
                break;
            }
            big++;
        }                
    }

    cout << answer;

    return 0;
}