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
    int orginIdx = 0;
    int valueIdx = 0;
    int pass = 0;

    for (int i = 0; i < n * n; ++i)
    {
        if (i != 0 && i % n == 0)
        {
            orginIdx++;
            pass += (n + 1);
        }
        valueIdx = i % n;
        
        if (i > pass)
        {
            //cout << orginIdx << " " << valueIdx << "\n";
            um[board[orginIdx] + board[valueIdx]]++;            
        }        
    }

    cout << um[k];
    return 0;
}