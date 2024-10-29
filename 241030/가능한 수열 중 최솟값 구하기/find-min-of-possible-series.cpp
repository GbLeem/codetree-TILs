#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> ans;
vector<vector<int>> answer;


bool Check(int value)
{
    if (ans.size() >= 3)
    {
        stack<int> s1;
        stack<int> s2;

        s2.push(value);
        int sizeA = ans.size();

        for (int i = sizeA - 1; i >= sizeA - 3; --i)
        {
            if (i == sizeA - 1)
                s2.push(ans[i]);
            else
                s1.push(ans[i]);
        }

        bool same = false;
        for (int i = 0; i < 2; ++i)
        {
            if (s1.top() == s2.top())
                same = true;
            else
                return false;
            s1.pop();
            s2.pop();
        }
        if (same)
            return true;
        else
            return false;
    }
    else
        return false;
}

void Choose(int cur)
{
    if (cur == n + 1)
    {        
        //Print();
        answer.push_back(ans);
        return;
    }

    for (int i = 4; i <= 6; ++i)
    {
        if (ans.empty() || ans.back() != i)
        {            
            if (!Check(i)) //여기서 체크가 실패한건 애초에 들어올수가없
            {
                ans.push_back(i);
                Choose(cur + 1);
                ans.pop_back();
            }
        }
    }
}

int main()
{
    cin >> n;

    Choose(1);

    for (auto a : answer[0])
        cout << a;
    return 0;
}