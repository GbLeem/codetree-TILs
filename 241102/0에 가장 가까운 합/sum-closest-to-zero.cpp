#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<int> board;
long long answer = INT_MAX + 2;

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
    long long minValue = INT_MAX + 2;

    for (int st = 0; st < n; ++st)
    {
        while (en != 0 && abs(board[en] + board[st]) < minValue)
        {            
            minValue = abs(board[en] + board[st]);
            en--;
            answer = min(answer, minValue);

            if(answer == 0)
            {
                cout << 0;
                return 0;
            }
        }

        if(en <= st)
            break;        
    }    
    //answer = min(answer, minValue);

    cout << answer;
    return 0;
}