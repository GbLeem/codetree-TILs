#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<int> board;
int answer = INT_MAX;

int main() 
{
    cin >> n;
    for(int i = 0; i < n ; ++i)
    {
        int num;
        cin >> num;
        board.push_back(num);
    }

    sort(board.begin(), board.end());

    int en = n - 1;
    int minValue = INT_MAX;

    for (int st = 0; st < n; ++st)
    {
        if(st < en)
            answer = min(answer, abs(board[st] + board[en]));

        while(st < en - 1 && board[st] + board[en] > 0)
        {
            en--;
            answer = min(answer, abs(board[st] + board[en]));
        }   
    }    

    cout << answer;
    return 0;
}