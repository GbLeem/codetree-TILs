#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> board;
char alpha[26] = { 'a', 'b', 'c', 'd', 'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
int answer = 0;
int cnt = 0;

int main()
{
    string str;
    int k;
    cin >> str >> k;

    //um 초기화
    for (int i = 0; i < 26; ++i)
    {
        board[alpha[i]] = 0;
    }

    //two pointer
    int en = 0;
    for (int st = 0; st < str.size(); ++st)
    {
        while (en <= str.size() && cnt <= k)
        {
            if (board[str[en]] == 0)
            {
                cnt++;
            }
            board[str[en]]++;
            en++;

            if (cnt > k)
            {
                break;
            }
        }
        answer = max(answer, en - st - 1);

        board[str[st]]--;
        if (board[str[st]] == 0)
            cnt--;
    }

    cout << answer;

    return 0;
}