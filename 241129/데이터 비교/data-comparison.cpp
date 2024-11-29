#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
unordered_set<int> s1;
int board[100'002];

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        s1.insert(num);
    }
    
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> board[i];
    }

    
    for(int i = 0; i < m; ++i)
    {        
        //찾으면
        if(s1.find(board[i]) != s1.end())        
            cout << 1 << " "; 
        
        else
            cout << 0 << " ";
    }

    return 0;
}