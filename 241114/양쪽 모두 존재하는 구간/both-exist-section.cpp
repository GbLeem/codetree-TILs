#include <iostream>
#include <climits>
using namespace std;

int n, m;
int board[100'002];

int nums[100'002];
int numsOut[100'002];

int answer = INT_MAX;

bool Check()
{
    for (int i = 1; i <= m; ++i)
    {
        if (nums[i] < 1)
            return false;
    }
    return true;
}

bool Check2()
{
    for (int i = 1; i <= m; ++i)
    {
        if (numsOut[i] < 1)
            return false;
    }
    return true;
}

bool Check3()
{   
    int temp[100'002];

    for(int i = 0; i < n; ++i)
    {
        temp[i] = numsOut[i];
    }
    for(int i = 1; i <= m; ++i)
    {
        temp[i] -= nums[i];
    }

    for(int i = 1; i <=m; ++i)
    {
        if(temp[i] < 1)
            return false;
    }
    return true;
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
        numsOut[board[i]]++;
    }

    int en = 0;
    nums[board[0]] = 1;
    numsOut[board[0]]--;

    for (int st = 0; st < n; ++st)
    {
        while (en < n && en >= st)
        {
            if (Check3())
            {
                answer = min(answer, en - st + 1);
                break;
                // if(Check2())                
                // {
                //     answer = min(answer, en - st + 1);
                //     break;
                // }
                // else
                //     break;
            }
            en++;
            nums[board[en]]++;
            numsOut[board[en]]--;
        }

        nums[board[st]]--;
        numsOut[board[st]]++;
    }
    if (answer == INT_MAX)
        cout << -1;
    else
        cout << answer;
    return 0;
}