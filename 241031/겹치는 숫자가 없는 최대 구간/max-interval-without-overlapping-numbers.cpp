#include <iostream>
using namespace std;

int n;
int board[100'002];
int vis[100'002];
int answer = 0;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
        vis[board[i]] = 0;
    }

    int en = 0;
    for(int st = 0; st < n; ++st)
    {
        while(en < n && vis[board[en]] == 0) //끝까지 안가고, 중복 없을 때
        {
            vis[board[en]]++;
            en++;
        }    
        answer = max(answer, en - st);        
        vis[board[st]]--;
    }

    cout << answer;

    return 0;
}