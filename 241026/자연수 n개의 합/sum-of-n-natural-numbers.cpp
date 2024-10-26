#include <iostream>
using namespace std;

long long s;

int main() 
{
    cin >> s; //합이 s이하
    long long left = 1;
    long long right = 2'000'000'000;
    long long max_num = 0;

    while(left <= right)
    {
        long long mid = (left + right) / 2;
        if(mid*(mid+1)/2 <=s)
        {
            left = mid + 1;
            max_num = max(max_num, mid);
        }
        else
            right = mid - 1;
    }
    
    cout << max_num;
    return 0;
}