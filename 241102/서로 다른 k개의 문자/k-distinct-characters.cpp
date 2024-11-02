#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> board;
char alpha[26] = {'a', 'b', 'c', 'd', 'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int answer = 0;
int cnt = 0;

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
        while(en < str.size() && cnt <= k)
        {                        
            //방문 안된 경우 cnt 증가
            if(board[str[en]] == 0)
            {
                board[str[en]] = 1;             
                cnt++;
            }

            //들어와서 새롭게 갱신된 경우 -> 잘못된 경우
            if(cnt > k)
            {
                board[str[en]] = 0;
                cnt--;
                break;          
            }
            en++;            

        }
        answer = max(answer, en - st);
        board[str[st]]--;
        cnt--;
    }

    cout << answer;
    return 0;
}