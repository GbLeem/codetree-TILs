#include <iostream>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int Dir(char ch)
{
    if(ch == 'N')
        return 3;
    else if(ch == 'E')
        return 0;
    else if(ch == 'S')
        return 1;
    else
        return 2;
}

int main() 
{
    int n;
    cin >> n;

    int dir = 0;
    int time = 0;

    int x = 0;
    int y = 0;

    for(int i = 0; i < n; ++i)
    {
        char ch;
        int num;
        cin >> ch >> num;

        dir = Dir(ch);

        for(int j = 1; j <= num; ++j)
        {
            x = x + dx[dir];
            y = y + dy[dir];
            time++;
            if(x == 0 && y == 0)
            {
                cout << time;
                return 0;
            }    
        }
        

    }

    cout << -1;
    return 0;
}