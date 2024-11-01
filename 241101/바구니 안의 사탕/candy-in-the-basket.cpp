#include <iostream>
using namespace std;

int n, k;
int board[1'000'002];
int answer = 0;
int maxPos = 0;

int main() 
{
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
    {
        int cnt, pos;
        cin >> cnt >> pos;
        board[pos] = cnt;
        maxPos = max(max, pos);
    }

    int en = 0;
    int sum = 0;

    for(int center = 1; center < maxPos; ++center)
    {
        if(board[center] != 0)
        {
            while(en <= center + k) //4 + 3
            {
                sum += board[en];        
                en++;
            }
            answer = max(answer, sum);            
            sum -= board[center];
        }
    }
    cout << answer;

    return 0;
}