#include <iostream>
#include <unordered_map>
using namespace std;

int n, k;
int board[100'002];
unordered_map<int, int> um_k; // 카운팅, 가장 많이 중복된 숫자
int answer = 0;
int maxKCnt = 0;

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    int en = 0;
    um_k[board[0]]++;
    maxKCnt++;

    for (int st = 0; st < n; ++st)
    {
        while (en < n && maxKCnt <= k)
        {
            en++;
            //방문 안한 경우
            if (um_k[board[en]] == 0)
            {
                um_k[board[en]] = 1;
            }
            //이미 방문한 경우
            else
            {
                um_k[board[en]]++;
                maxKCnt = max(maxKCnt, um_k[board[en]]);
            }

        }
        answer = max(answer, en - st);       

        //만약 maxKCnt가 것이 st였고 다른 maxKCnt 없다면,
        if(um_k[board[st]] == maxKCnt)
            maxKCnt--;
        um_k[board[st]]--;                
            
    }

    cout << answer;

    return 0;
}