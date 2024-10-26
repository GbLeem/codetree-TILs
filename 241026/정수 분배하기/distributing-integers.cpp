#include <iostream>
using namespace std;

int n, m;
int board[10'002];

bool IsPossible(int k)
{
    int cnt = 0;

    for(int i = 0; i < n; ++i)
    {
        int temp = board[i];

        while(temp >= k)
        {
            temp -= k;
            cnt++;;
        }
    }
    
    if(cnt >= m)
        return true;
    else
        return false;
}

int main() 
{
    cin >> n >> m;
    int maxNum = 0;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
        maxNum = max(maxNum, board[i]);
    }

    int left = 1;
    int right = maxNum;
    int answer = 0;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(IsPossible(mid))
        {
            left = mid + 1;
            answer = max(answer, mid);
        }
        else
            right = mid - 1;
    }

    cout << answer;

    return 0;
}