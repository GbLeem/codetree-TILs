#include <iostream>
#include <climits>
using namespace std;

int n, s;
int board[100'002];
int answer = INT_MAX;
int total = 0;

int main() 
{
    //6 3 2 4 9 1
    //i
    //j

    cin >> n >> s;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
        total += board[i];
    }

    int tempSum = 0;
    int en = 0;

    for(int st = 0; st < n; ++st)
    {
        while(en < n && tempSum + board[en] < s)
        {
            tempSum += board[en];
            en++;
        }
        if(total == tempSum)
        {
            cout << -1;
            return 0;
        }
        
        if(tempSum + board[en] < s)
            continue;
        answer = min(answer, en - st + 1);
        tempSum -= board[st];        
    }

    cout << answer;
    return 0;
}