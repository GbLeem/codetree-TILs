#include <iostream>
using namespace std;

int board[100'002];

int main() 
{
    string str;
    cin >> str;

    int sSize = str.size();

    for(int i = sSize; i >= 0; --i)
    {
        if(str[i] == ')' && str[i + 1] == ')')
        {
            board[i] = board[i+1] + 1;
        }
        else
            board[i] = board[i+1];
    }

    long long answer = 0;
    for(int i = 0; i < sSize; ++i)
    {
        if(str[i] == '(' && str[i+1] == '(')
            answer += board[i+2];
    }

    cout << answer;
    return 0;
}