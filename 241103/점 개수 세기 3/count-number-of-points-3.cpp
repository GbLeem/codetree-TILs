#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, q;
int board[100'002];
//set<int> s;
unordered_map<int, int> um;

int main() 
{
    cin >> n >> q;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];        
    }
    sort(board, board + n);
    
    int cnt = 1;

    for(int i = 0; i < n; ++i)
    {
        um[board[i]] = cnt;    //um[-3] = 1
        board[i] = cnt;       //board[0] = 1;
        cnt++;
    }    
    
    // for(int i = 0; i < n; ++i)
    //     cout << board[i] <<" ";
        
    for(int i = 0; i < q; ++ i)
    {
        int a, b;
        cin >> a >> b;
        a = um[a];
        b = um[b];

        cout << b - a + 1 << "\n";
    }
    return 0;
}