#include <iostream>
#include <queue>
using namespace std;

int n;
int board[100'002];
float answer = 0;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i]; // 3 1 9 2 7 
    }
    
    //k : 1 ~ n-2    
    for(int k = 1; k <= n - 2; ++k)
    {
        //k개 제거
        int tempK = k;

        priority_queue<int> tempPQ;

        for(int i = tempK; i < n; ++i)
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
     
    printf("%.2f", answer);

    return 0;
}