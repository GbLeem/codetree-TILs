#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int n, q;
int board[100'002];
set<int> s;
unordered_map<int, int> um;

int main() 
{
    cin >> n >> q;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
        s.insert(board[i]);
    }        

    set<int>::iterator it;

    int cnt = 1;
    for(it = s.begin(); it != s.end(); ++it)
    {
        um[*it] = cnt;
        //cout << *it << " -> " << cnt<<"\n";
        board[*it] = cnt;
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