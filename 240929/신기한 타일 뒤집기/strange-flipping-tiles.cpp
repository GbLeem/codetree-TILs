#include <iostream>
using namespace std;

pair<int, char> board[200002];

int main() 
{
    int n;
    cin >> n;

    int cur = 0;
    for(int i = 0; i < n; ++i)
    {
        int num;
        char ch;
        cin>> num >> ch;

        if(ch == 'L')
        {
            for(int i = cur + 100000; i > cur - num + 100000; --i)
            {
                board[i].first++;
                board[i].second = 'W';
            }
            cur = cur - num + 1;
        }
        else
        {
            for(int i = cur + 100000; i < cur + num + 100000; ++i)
            {
                board[i].first++;
                board[i].second = 'B';
            }
            cur = cur + num - 1;
        }
    }

    int black = 0;
    int white = 0;

    for(int i = 0; i <= 200000; ++i)
    {
        if(board[i].second == 'B')
            black++;
        if(board[i].second == 'W')
            white++;
    }

    cout << white <<" "<< black;
    return 0;
}