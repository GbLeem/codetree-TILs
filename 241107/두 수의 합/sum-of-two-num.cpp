#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, k;
int board[100'002];
unordered_map<int, int> numCount;
int answer = 0;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
        numCount[board[i]]++;
    }
    sort(board, board + n);
    for (int i = 0; i < n; ++i)
    {
        int temp = k - board[i];

        //필요한 값이 있으면,
        if (numCount[temp] > 0)
        {
            if (temp == board[i])
            {
                answer += (numCount[temp] - 1);
                numCount[temp]--;
            }
            else
            {
                answer++;
                numCount[temp]--;
                numCount[board[i]]--;
            }
        }
    }

    cout << answer;

    return 0;
}