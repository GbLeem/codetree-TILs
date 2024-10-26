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

        if(!binary_search(board.begin(), board.end(), num))
            cout << -1 << "\n";
        else
            cout << lower_bound(board.begin(), board.end(), num) - board.begin() + 1<< "\n";
    }
    return 0;
}