#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> ans;

void Print()
{
    for(auto a : ans)
        cout << a << " ";
    cout << "\n";
}

void Choose(int cur, int cnt)
{
    if(cur == n + 1) //n개 탐색
    {
        if(cnt == m) //m개 선택 
        {
            Print();                    
        }
        return;
    }

    ans.push_back(cur);    
    Choose(cur + 1, cnt + 1);    
    ans.pop_back();

    Choose(cur + 1, cnt);
}

int main() 
{
    cin >> n >> m;

    Choose(1, 0);    
    
    return 0;
}