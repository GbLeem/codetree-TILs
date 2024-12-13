#include <iostream>
#include <climits>
using namespace std;

int board[102];
int answer = INT_MAX;

int main() 
{
    //최소 t번 이상 h높이가 되도록
    int n, h, t;
    cin >> n >> h >> t;
    
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }    

    //t보다 크거나 같은것 찾기

    for(int i = 0; i < n; ++i)
    {
        int cnt = t;
        int temp = 0;
        
        for(int j = i; j < n; ++j)
        {
            int cost = abs(h - board[j]);
            
            cnt--;
            temp += cost;
            
            if(cnt == 0)
                break;
        }

        answer = min(answer, temp);
    }

    cout <<answer;
    return 0;
}