#include <iostream>
using namespace std;

int board1[1'000'002];
int board2[1'000'002];

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
    for(int i = 0; i < m; ++i)
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
    int big = 0; //1은 A 2는 B 3은 같음
    int answer = 0;


    for(int i = 1; i < time; ++i)
    {
        if(first)
        {
            if(board1[i] > board2[i])            
                big = 1;
            else if(board1[i] < board2[i])
                big = 2;

            answer++;
            first = false;
        }

        else if(!first)
        {
            if(big == 1)
            {
                if(board1[i] < board2[i])
                {
                    answer++;
                    big = 2;
                }       
                else if(board1[i] == board2[i])
                {
                    answer++;
                    big = 3;
                }
            }
            else if(big == 2)
            {
                if(board1[i] > board2[i])
                {
                    answer++;
                    big = 1;
                }       
                else if(board1[i] == board2[i])
                {
                    answer++;
                    big = 3;
                }
            }
            else if(big == 3)
            {
                if(board1[i] > board2[i])
                {
                    answer++;
                    big = 1;
                }       
                else if(board1[i] < board2[i])
                {
                    answer++;
                    big = 2;
                }
            }
        }
    }
    

    cout << answer;
    return 0;
}