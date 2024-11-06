#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, k;
int board[100'002];
unordered_map<int, int> um;
int answer = 0;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }
    sort(board, board + n);
    // 3 4 5 6 7

    int en = 1;
    for(int st = 0; st < n; ++st)
    {
        en = st + 1;
        while(en < n && board[st] + board[en] < k)
        {
            en++;
        }
        if(board[st] + board[en] == k)
        {
            um[k]++;
        }
    }
    
    cout << um[k];
    return 0;
}