#include <iostream>
#include <climits>
using namespace std;

int n, m;
int board[55][55];
int d[55][55]; //x위치 y위치 최근에 현재 값
//현재보다 큰 수로 이동
//최소 x+1, y+1 한 위치

void Print()
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cout << d[i][j] <<" ";
        }
        cout <<"\n";
    }
}

int main() 
{
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> board[i][j];
            d[i][j] = INT_MIN;
        }
    }

    //i j 위치에 왔을때 최대 칸의 수
    d[1][1] = 1; //시작점을 1
    int start = board[1][1];

    //현재 위치
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            //현재 위치보다 작은 것들 체크
            for(int k = 1; k < i; ++k)
            {
                for(int l = 1; l < j; ++l)
                {             
                    //도달하는 것이 불가능한 경우
                    if(d[k][l] == INT_MIN)
                        continue;
                    
                    if(board[i][j] > board[k][l] && i > k && j > l)
                    {
                        d[i][j] = max(d[i][j], d[k][l] + 1);
                    }                       
                }
            }
        }
    }

    //Print();

    int answer = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {  
            answer = max(answer, d[i][j]);
        }
    }

    cout << answer;

    return 0;
}