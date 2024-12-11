#include <iostream>
#include <vector>
using namespace std;

int n;
char ch;
string board[22];
vector<string> vec;
int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    cin >> ch;

    for(int i = 0; i < n; ++i)
    {
        if(board[i][board[i].size()-1] == ch)
            vec.push_back(board[i]);
    }

    cout << vec.size()<<"\n";
    for(auto v : vec)
    {
        cout << v << "\n";
    }
    return 0;
}