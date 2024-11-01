#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<int> board;
int answer = INT_MAX;

//테스트케이스 5번
int main() 
{
    cin >> n;
    for(int i = 0; i < n ; ++i)
    {
        int num;
        cin >> num;
        board.push_back(num);
    }

    sort(board.begin(), board.end()); //-123 1 1 2 2 124

    int en = n - 1;

    for (int st = 0; st < n; ++st)
    {
        int minValue = INT_MAX; 
        while (en != 0 && abs(board[en] + board[st]) <= minValue)
        {            
            minValue = abs(board[en] + board[st]); //1
            en--;
            answer = min(answer, minValue);
        }

        if(en <= st)
            break;        
    }    

    cout << answer;
    return 0;
}