#include <iostream>
using namespace std;

//E S W N 순서
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() 
{
    string str;
    cin >> str;

    int dir = 3;
    int x = 0;
    int y = 0;
    int answer = 0;

    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == 'F')
        {
            x = x + dx[dir];
            y = y + dy[dir];
        }
        else if(str[i] == 'L')
        {
            dir = (dir + 3) % 4;
        }
        else if(str[i] == 'R')
        {
            dir = (dir + 1) % 4;
        }    
        answer++;
        //cout << x <<" "<< y <<"\n";
        if(x == 0 && y == 0)
        {
            cout << answer;
            return 0;
        }
    }
    cout << -1;

    return 0;
}