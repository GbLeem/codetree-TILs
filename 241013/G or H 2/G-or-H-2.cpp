#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char board[102];
vector<int> dist;

int main() 
{
    int n;
    cin >> n;

    int maxNum = 0;

    for(int i = 0; i < n; ++i)
    {
        int num;
        char ch;
        cin >> num >> ch;

        maxNum = max(maxNum, num);
        board[num] = ch;
    }
    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= maxNum; ++i) //시작점
    {
        if(board[i] == 'G')
        {
            int g = 0;    
            int h = 0;
            g++;
            for(int j = i + 1; j <= maxNum; ++j)
            {
                if(board[j] == 'G')
                {
                    g++;
                    if(g == h || (g == 0 && h != 0) || (g != 0 && h ==0))
                        dist.push_back(j - i);
                }
                else if(board[j] == 'H')
                {
                    h++;
                    if(g == h || (g == 0 && h != 0) || (g != 0 && h ==0))
                        dist.push_back(j - i);
                }

            }    
        }
        else if(board[i] == 'H')
        {
            int g = 0;    
            int h = 0;
            h++;        
            for(int j = i + 1; j <= maxNum; ++j)
            {
                if(board[j] == 'G')
                {
                    g++;
                    if(g == h || (g == 0 && h != 0) || (g != 0 && h ==0))
                        dist.push_back(j - i);
                }
                else if(board[j] == 'H')
                {
                    h++;
                    if(g == h || (g == 0 && h != 0) || (g != 0 && h ==0))
                        dist.push_back(j - i);
                }
            }    
        }
    }

    cout << *max_element(dist.begin(), dist.end());

    return 0;
}