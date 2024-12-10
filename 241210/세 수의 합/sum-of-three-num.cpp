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
        bool find = false;
        int temp = k - board[i];
        um[board[i]]--; //1

        //두개의 합이 temp인 것 찾기
        for (int j = i + 1; j < n; ++j)
        {
            //other 과 board[j]
            int other = temp - board[j]; //2
            um[board[j]]--;

            if (um[other] > 0)
            {
                find = true;
                answer++;
            }

            if (!find)
            {
                um[board[j]]++;
                um[board[i]]++;
            }
        }
    }

    cout << answer;




    return 0;
}