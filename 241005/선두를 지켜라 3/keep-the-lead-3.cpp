#include <iostream>
using namespace std;

int board1[1000002];
int board2[1000002];

int main() 
{
    int n, m;
    cin >> n >> m;

    int cur = 1;
    int dist = 0;

    for(int i = 0; i < n; ++i)
    {
        int v, t;
        cin >> v >> t;

        for(int j = cur; j < cur + t; ++j)
        {
            board1[j] = dist + v;
            dist += v;
        }    
        cur = cur + t;
    }
    int time = cur;

    cur = 1;
    dist = 0;
    for(int i = 0; i < n; ++i)
    {
        int v, t;
        cin >> v >> t;

        for(int j = cur; j < cur + t; ++j)
        {
            board2[j] = dist + v;
            dist += v;
        }    
        cur = cur + t;
    }
    
    bool first = true;
    bool A = false;
    int answer = 0;

    for(int i = 0; i < time; ++i)
    {
        if(first)
        {
            if(board1[i] > board2[i])            
                A = true;
            else if(board1[i] < board2[i])
                A = false;

            answer++;
            first = false;
        }

        if(!first)
        {
            if(A && board1[i] < board2[i])
            {
                answer+=2;
                A = false;
            }
            else if(!A && board1[i] > board2[i])
            {
                answer+=2;
                A = true;
            }
        }
    }
    

    cout << answer;
    return 0;
}