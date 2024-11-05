#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> board;

void Print()
{
    for(int i = 0; i < board.size(); ++i)
    {
        cout << board[i]<<" ";
        if(i % n == n - 1)
            cout <<"\n";
    }
}

int main() 
{
    cin >> n;
    cin >> k;

    for(int i = 0; i < n * n; ++i)
    {
        int y = i % n + 1;
        int x = i / n + 1;
        board.push_back(x * y);
    }

    //Print();
    sort(board.begin(), board.end());
    
    //Print();

    cout << board[k - 1];

    
    return 0;
}