#include <iostream>
#include <queue>
using namespace std;

int n;
int board[100'002];
priority_queue<int, vector<int>, greater<int>> pq; //최소힙
double answer = 0;
int sum = 0;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i]; // 3 1 9 2 7 
    }
     // 1 2 3 7 9 
    pq.push(board[n - 1]); //7
    sum += board[n-1]; //7
    
    for(int k = n - 2; k >= 1; --k)
    {
        pq.push(board[k]); // 2 7 9
        sum += board[k]; //9

        answer = max(answer, (double)(sum - pq.top()) / (pq.size() - 1));

    }
    
    cout << fixed;
    cout.precision(2);

    cout << answer;

    return 0;
}