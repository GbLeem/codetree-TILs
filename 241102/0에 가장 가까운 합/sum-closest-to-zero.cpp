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
            //조건을 만족하지 못했는데, 모든 경우 다 봤다면
            if(en <= st)        
                break;        
        }
        en++;
        if(en <= st)        
            break;   
    }    

    cout << answer;
    return 0;
}