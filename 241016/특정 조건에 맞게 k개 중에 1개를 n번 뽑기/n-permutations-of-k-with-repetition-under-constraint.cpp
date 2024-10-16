#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> ans;

bool Check()
{
    int temp = ans[0];
    int cnt = 1;
    int maxCnt = 0;

    for (int i = 1; i < ans.size(); ++i)
    {
        if (temp != ans[i])
        {
            temp = ans[i];
            maxCnt = max(cnt, maxCnt);
            cnt = 1;
        }
        else
            cnt++;
    }
    maxCnt = max(cnt, maxCnt);

    if (maxCnt >= 3)
        return false;
    return true;
}

void Print()
{
    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << "\n";
}

void Choose(int cur)
{
    if (cur == n + 1)
    {
        Print();
        return;
    }

    for (int i = 1; i <= k; ++i)
    {        
        ans.push_back(i);
        if(Check())
            Choose(cur + 1);
        ans.pop_back();
     
    }
}

int main()
{
    //연속하여 같은 숫자 3번 x 
    cin >> k >> n; //k 이하의 숫자 n번 고르기

    Choose(1);

    return 0;
}