#include <iostream>
#include <queue>
using namespace std;

int n;
int board[100'002];
priority_queue<int, vector<int>, greater<int>> pq;
float answer = 0;
int minValue = 0;
int sum = 0;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i]; // 3 1 9 2 7 
        pq.push(board[i]);
        sum += board[i];
    }
    
    minValue = pq.top(); //가장 작은 값    
    int cnt = n - 1; //가장 작은 값을 제외한 사이즈

    //k : 1 ~ n-2
    for(int k = 1; k <= n - 2; ++k)
    {   
        int removeValue = board[k - 1]; // 없앨 값      

        if(removeValue == minValue)      // 가장 작은 값 리셋    
        {
            pq.pop();
            minValue = pq.top();
        }
                    
        sum -= removeValue; //없애기          
        cnt--;
        //cout << cnt << " " << minValue << "\n";

        answer = max(answer, (float)(sum - minValue) / cnt);
    }
    
    cout << fixed;
    cout.precision(2);
    cout << answer;

    return 0;
}