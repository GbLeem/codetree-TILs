#include <iostream>
#include <queue>
using namespace std;

int t, m;

int main() 
{
    cin >> t;
    while(t--)
    {
        cin >> m;
        priority_queue<int> pq;

        for(int i = 1; i <= m; ++i)
        {
            int num;
            cin >> num;
            pq.push(num);
            
            if(i % 2 != 0)
            {
                priority_queue<int> tempPQ = pq;
                vector<int> board;
                while(!tempPQ.empty())    
                {
                    board.push_back(tempPQ.top());
                    tempPQ.pop();
                }
                cout << board[board.size()/2] <<" ";
            }            
        }
        cout << "\n";
    }
    return 0;
}