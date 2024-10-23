#include <iostream>
using namespace std;

int n; //n개의 층
int board[102];
int s1, e1, s2, e2;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }
    cin >> s1 >> e1 >> s2 >> e2;

    //s1-1 에서 e1-1까지 지우기

    int temp[102];
    int temp_cur = 0;
    
    for(int i = 0; i < n; ++i)
    {
        if(s1 - 1 <= i && i <= e1 - 1)
            continue;
        temp[temp_cur] = board[i];
        temp_cur++;
    }

    //1 1 5

    for(int i = 0; i < temp_cur; ++i)
    {
        board[i] = temp[i];   
    }
    n = temp_cur;
    temp_cur = 0;
    for(int i = 0; i < n; ++i)
    {
        if(s2 - 1 <= i && i <= e2 - 1)
            continue;
        temp[temp_cur] = board[i];
        temp_cur++;
    }

    n = temp_cur;
    cout << n <<"\n";
    for(int i = 0; i < n; ++i)
    {
        cout << temp[i]<<"\n";
    }
    return 0;
}