#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int cur = 0;
int st = 0;
int en = 0;
vector<pair<int,int>> pos;
int answer = 0;

int main() 
{   
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
    {
        int num;
        char ch;
        cin >> num >> ch;
        
        if(ch == 'R')
        {
            st = cur;
            en = cur + num;
            cur += num;        
        }   
        else
        {
            st = cur - num;
            en = cur;
            cur -= num;
        }         
        pos.push_back({st, +1});
        pos.push_back({en, -1});        
    }
    sort(pos.begin(), pos.end());

    int tempSum = 0;

    for(int i = 0; i < 2 * n; ++i)
    {
        tempSum += pos[i].second;
        if(tempSum >= k)
            answer++;    
    }
    cout << answer;

    return 0;
}