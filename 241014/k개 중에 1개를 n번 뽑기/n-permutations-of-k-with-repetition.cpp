#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
int k, n;

void Print()
{
    for(int i = 0; i <ans.size(); ++i)
    {
        cout << ans[i] <<" ";
    }
    cout <<"\n";
}

//현재 위치 cur
void Choose(int cur)
{
    if(cur == n + 1)
    {
        Print();
        return;
    }

    //k이하의 숫자를 뽑아주삼
    for(int i = 1 ; i <= k; ++i)
    {
        ans.push_back(i);
        Choose(cur + 1);
        ans.pop_back();
    }
}

int main() 
{
    cin >> k >> n;

    Choose(1);
    return 0;
}