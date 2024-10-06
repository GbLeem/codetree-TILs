#include <iostream>
using namespace std;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0 ,0 ,-1};

bool Range(int x, int y, int n)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

int Dir(char ch)
{
    int dir = 0;

    if(ch == 'U')
        dir = 2;    
    else if(ch == 'D')
        dir = 1;
    else if(ch == 'R')
        dir = 0;
    else if(ch == 'L')
        dir = 3;

    return dir;
}

int main() 
{
    int n, t;
    cin >> n >> t;

    int r, c;
    char d;
    cin >> r >> c >> d;

    int dir = Dir(d); //행 열    
    int x = r - 1;
    int y = c - 1;

    while(t--)
    {                       
        x = x + dx[dir];
        y = y + dy[dir];

        if(!Range(x, y, n))
        {
            dir = 3 - dir;
            t++;
        }
    }
    cout << x + 1 <<" "<< y + 1;
    return 0;
}