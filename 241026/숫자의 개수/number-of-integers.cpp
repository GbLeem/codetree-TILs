#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> board;

int main() 
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        board.push_back(num);
    }

    for(int i = 0; i < m; ++i)
    {
        int num;
        cin >> num;

        cout << upper_bound(board.begin(), board.end(), num) - lower_bound(board.begin(), board.end(), num) <<"\n";
    }
    return 0;
}