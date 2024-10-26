#include <iostream>
#include <climits>
using namespace std;

long long n;

bool Count(int k)
{
    long long cnt = k / 3 + k / 5 - k / 15;
    
    if(k - cnt >= n)
        return true;

    return false;
}

int main() 
{
    cin >> n;
    
    long long left = 1;
    long long right = INT_MAX;
    long long answer = INT_MAX;

    while(left <= right)
    {
        long long mid = (left + right) / 2;

        if(Count(mid))
        {
            right = mid - 1;
            answer = min(answer, mid);
        }
        else
            left = mid + 1;
    } 
            
    cout << answer;
    return 0;
}