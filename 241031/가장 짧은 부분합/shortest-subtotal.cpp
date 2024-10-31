#include <iostream>
#include <climits>
using namespace std;

int n, s;
int board[100'002];
int answer = INT_MAX;

int main() 
{
    //6 3 2 4 9 1
    //i
    //j

    cin >> n >> s;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    for(int st = 0; st < n; ++st)
    {
        int tempSum = 0;
        for(int en = st; en < n; ++en)
        {
            tempSum += board[en];
            if(tempSum >= s)
            {
                answer = min(answer, en - st + 1);            
                break;
            }
        }
    }
    
    cout << answer;
    return 0;
}