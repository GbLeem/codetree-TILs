#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
unordered_map<string, int> um;

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        char board[1000];
        for(int j = 0; j < str.size(); ++j)
        {
            board[i] = str[i];
        }
        sort(board, board + str.size());

        string temp;
        for(int j = 0; j < str.size(); ++j)
        {
            temp += board[j];
        }        
        um[temp]++;
    }
    
    int answer = 0;
    for(auto it = um.begin(); it != um.end(); ++it)
    {
        answer = max(answer, it->second);
    }
    cout<<answer;
    return 0;
}