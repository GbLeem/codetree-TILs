#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> board;
char alpha[26] = {'a', 'b', 'c', 'd', 'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int answer = 0;

int main() 
{
    string str;
    int k; 
    cin >> str;
    cin >> k;

    for(int i = 0; i < 26; ++i)
    {
        board[alpha[i]] = 0;
    }
    
    int en = 0;
    for(int st = 0; st < str.size(); ++st)
    {
        while(en < str.size() && board[str[en]] <= k)
        {
            board[str[en]]++;
            en++;
        }
        answer = max(answer, en - st);
        board[str[st]]--;
    }

    cout << answer;
    return 0;
}