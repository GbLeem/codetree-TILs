#include <iostream>
using namespace std;

//r는 i /  c은 j일 때

int n, m; //옷 종류 / 날짜
int board[202][3];
int d[202][202]; //r : 종류 c : 날짜 일때 만족도
int answer = 0;

int main() 
{
    cin >> n >> m;
    for(int i = 1 ; i <= n; ++i)
    {
        int s, e, v;
        cin >> s >> e >> v;
        //i는 종류
        board[i][0] = s; //시작
        board[i][1] = e; //끝
        board[i][2] = v; //만족도
    }


    //1일차
    //d[1][1] = 0;
    //d[2][1] = 5;
    for(int i = 1; i <= n; ++i)
    {
        if(board[i][0] <= 1)
            d[1][i] = board[i][2];
        else
            d[1][i] = 0;
    }
    
    //2일차 1을 선택했을 때는 1일차 dp값에서 
    //d[1][2] = max(board[i][2] - d[1][1])
    
    //m일 까지
    for(int i = 2; i <= m; ++i)
    {
        //종류
        for(int j = 1; j <= n; ++j)
        {               
            //날짜 체크
            if(board[j][0] <= i && i <= board[j][1])
            {
                for(int k = 1; k <= n; ++k)
                {       
                    if(d[i-1][k] != 0)             
                        d[i][j] = max(abs(board[j][2] - board[k][2]), d[i][j]);                                                                    
                }
            }
        }
    }

   
    //날짜
    for(int i = 2; i <= m; ++i)
    {
        int maxV = 0;
        //종류
        for(int j = 1; j <= n; ++j)
        {
            maxV = max(maxV, d[i][j]);
        }
        answer += maxV;
    }

    cout << answer;

    return 0;
}