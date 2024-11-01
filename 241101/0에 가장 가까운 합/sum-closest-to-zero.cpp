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

    int en = 1;

    sort(board.begin(), board.end()); //-123 1 1 2 2 124    

    for (int st = 0; st < n; ++st)
    {
        int minValue = INT_MAX;

        while (en != n)
        {
            if (abs(board[en] + board[st]) <= minValue)
            {
                minValue = abs(board[en] + board[st]);
                en++;
            }
            else
                break;
        }
        answer = min(answer, minValue);
    }    

    cout << answer;
    return 0;
}