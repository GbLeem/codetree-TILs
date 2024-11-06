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

    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            um[board[i] + board[j]]++;
            if(board[i] + board[j] > k)
                break;
        }
    }
    
    cout << um[k];
    return 0;
}