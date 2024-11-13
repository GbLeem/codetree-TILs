#include <iostream>
#include <climits>
using namespace std;

int n;
int board[102];
int answer = INT_MAX;
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    for (int i = 0; i < n; ++i)  //두배할 것 설정
    {
        int temp[102] = {};
        int idx = 0;

        for (int j = 0; j < n; ++j) //제외할 것 설정
        {
            int tempSum = 0;
            for (int k = 0; k < n; ++k)
            {
                if (j == k)
                    continue;                
                if(i == k)
                    temp[idx++] = board[k]*2;
                else
                    temp[idx++] = board[k];
            }
            for (int k = 0; k < n - 2; ++k)
            {
                tempSum += abs(temp[k] - temp[k + 1]);
            }
            answer = min(answer, tempSum);
        }
    }
    cout << answer;
    return 0;
}