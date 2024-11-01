#include <iostream>
#include <queue>
using namespace std;

int n;
int board[100'002];
priority_queue<int> pq;
float answer = 0;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i]; // 3 1 9 2 7 
    }
    
    //k : 1 ~ n-2    
    for(int k = 1; k <= n - 2; ++k)
    {               
        priority_queue<int> tempPQ;
        
        for(int i = k; i < n; ++i)
        {
            tempPQ.push(board[i]);    
        }

        float tempValue = 0;
        int cnt = 0;

        while(tempPQ.size() > 1)
        {
            tempValue += tempPQ.top();
            tempPQ.pop();
            cnt++;
        }
        //cout << (float)tempValue / cnt << "\n";
        answer = max(answer, tempValue / cnt);
    }
    
    cout << fixed;
    cout.precision(2);
    cout << answer;

    return 0;
}