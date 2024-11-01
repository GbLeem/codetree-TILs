#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> pq;
float answer = 0;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        pq.push(num);    
    }
    
    //k : 1 ~ n-2    
    for(int k = 1; k <= n-2; ++k)
    {
        priority_queue<int> tempPQ = pq;

        //k개 제거
        int tempK = k;
        while(tempK--)
        {
            tempPQ.pop();
        }
        int tempValue = 0;
        int cnt = 0;
        while(tempPQ.size() > 1)
        {
            tempValue += tempPQ.top();
            tempPQ.pop();
            cnt++;
        }
        answer = max((float)answer / cnt);
    }
    
    cout << fixed;
    cout.precision(2);
    cout << answer;
    
    return 0;
}