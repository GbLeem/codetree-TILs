#include <iostream>
#include <unordered_map>
using namespace std;

int n, k;
unordered_map<int, int> um;
int board[1002];
int answer = 0;

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
        um[board[i]]++;
    }

    for (int i = 0; i < n; ++i)
    {
        int temp = k - board[i];
        um[board[i]]--;

        int reset1 = -1;
        int reset2 = -1;
        //두개의 합이 temp인 것 찾기

        for (int j = 0; j < n; ++j)
        {
            int other = temp - board[j];

            if (um[other] >= 1)
            {
                if (other == board[j])
                {
                    if (other != board[i])
                    {
                        um[other]--;
                        answer += um[other]; // 4 3 2 1 
                        reset1 = other;
                        reset2 = other;
                    }
                    else
                    {                        
                        answer += um[other];
                        um[other]--;
                    }
                }
                else
                {
                    if (um[board[j]] > 0)
                    {
                        answer += um[other];
                        um[board[j]] = 0;
                        reset1 = other;
                        reset2 = board[j];
                    }
                }
            }
        }
        //뭐라도 한 번 찾은 경우
        if (reset1 != -1 && reset2 != -1)
        {
            um[reset1]++;
            um[reset2]++;
        }
        else
        {
            um[board[i]]++;
        }
    }

    cout << answer;

    return 0;
}