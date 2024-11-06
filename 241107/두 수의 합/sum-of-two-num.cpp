#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int n, k;
int board[100'002];
unordered_set<int> us1;
unordered_set<int> us2;

int answer = 0;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }
    
    for(int i = 0; i < n; ++i)
    {
        int temp = k - board[i]; //필요한 수가 뭔지
        
        if (us1.count(temp) && !us2.count(temp)) //이전에 등장했다면,
        {
            answer++;
            us2.insert(board[i]);
        }
        //등장안했으면
        us1.insert(board[i]);
    }

    cout << answer;
    return 0;
}