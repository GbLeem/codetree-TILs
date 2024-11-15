#include <iostream>
#include <climits>
using namespace std;

int n, k;
int board[1'000'002];
int answer = INT_MAX;

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    int one = 0;
    int two = 0;
    int en = 0;

    if (board[0] == 1)
        one++;
    else
        two++;

    for (int st = 0; st < n; ++st)    //1을 가리킨다.
    {
        while (one < k && en + 1 < n)
        {
            if (en + 1 == n)
                break;
            en++;
            if (board[en] == 1)
                one++;
            else
                two++;           
        }
        if(one >= k)
            answer = min(answer, en - st + 1);

        if (board[st] == 1)
            one--;
        else
            two--;
    }

    if (answer == INT_MAX)
        cout << -1;
    else
        cout << answer;
    return 0;
}