#include <iostream>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() 
{
    string str; 
    cin >> str;
    
    pair<int, int> cur = {0, 0};
    int dir = 0;

    for(int i = 0; i < str.size(); ++i)
    {        
        if(str[i] == 'R') //90도
        {
            dir = (dir + 1) % 4;
        } 
        else if(str[i] == 'L') //-90도
        {
            dir = (dir - 1 + 4) % 4;
        }
        else if(str[i] == 'F')
        {
            cur.first = cur.first + dx[dir];
            cur.second = cur.second + dy[dir];
        }
    }

    cout << cur.first << " "<< cur.second;    
    
    return 0;
}