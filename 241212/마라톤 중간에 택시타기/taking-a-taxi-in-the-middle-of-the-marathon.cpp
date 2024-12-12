#include <iostream>
#include <climits>
using namespace std;

int n;
int L[100'002];
int R[100'002];
pair<int,int> board[100'002];
int answer = INT_MAX;


void Print()
{
    for(int i = 0; i < n; ++i)
    {
        cout << L[i]<<" ";
    }
    cout <<"\n";
    for(int i = 0; i < n; ++i)
    {
        cout << R[i]<<" ";
    }
    cout <<"\n";
}

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i].first >> board[i].second;                
    }

    L[0] = 0;

    for(int i = 1; i < n; ++i)
    {
        L[i] = L[i-1] + abs(board[i].first - board[i-1].first) + abs(board[i].second - board[i-1].second);
    }

    R[n-1] = 0;
    for(int i = n-2; i >= 0; --i)
    {
        R[i] = R[i+1] + abs(board[i].first - board[i+1].first) + abs(board[i].second - board[i+1].second);
    }
    
    //Print();
    
    //0번이랑 n번 빼기
    for(int i = 1; i < n - 1; ++i)
    {
        answer = min(answer, L[i-1] + R[i+1] + abs(board[i+1].first - board[i-1].first) + abs(board[i+1].second - board[i-1].second));
    }

    cout << answer;
    return 0;
}