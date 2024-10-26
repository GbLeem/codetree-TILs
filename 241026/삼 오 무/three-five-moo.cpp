#include <iostream>
using namespace std;

int n;
int M = 1'000'000;

bool Count(int k)
{
    int temp = n;
    for(int i = 1; i <= k; ++i)
    {
        if(i % 3 != 0 && i % 5 != 0)
            temp--;

        if(temp == 0)
        {
            return true;
        }
    }

    return false;
}

int main() 
{
    cin >> n;
    
    int left = 1;
    int right = M;
    int answer = M;

    while(left <= right)
    {
        int mid = (left + right) / 2;

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