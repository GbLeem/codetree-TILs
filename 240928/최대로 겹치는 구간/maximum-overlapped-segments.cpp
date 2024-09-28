#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> board;
int line[205];

int main() 
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        board.push_back({a + 100, b + 100}); //0 ~ 200
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = board[i].first; j < board[i].second; ++j)
        {
            line[j]++;
        }
    }

    cout << *max_element(line, line + 200);


    return 0;
}