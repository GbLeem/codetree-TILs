#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, k;
int board[100'002];
vector<int> ans;
unordered_map<int, int> um;
int answer = 0;

void Print()
{
    for (auto a : ans)
        cout << a << " ";
    cout << "\n";
}
bool Check()
{
    int temp = 0;
    for (auto a : ans)
    {
        temp += board[a];
    }
    if (temp == k)
        return true;
    return false;
}

void Choose(int cur)
{
    if (cur == 3)
    {
        //Print();
        if (Check())
            answer++;
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        //비어있지 않을땐 쓴적 없음, 비어있을땐 인덱스보다 커야함
        if (um[i] == 0)
        {
            if (!ans.empty() && ans[0] > i)
                continue;
            ans.push_back(i);
            um[i]++;
            Choose(cur + 1);
            ans.pop_back();
            um[i]--;
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    Choose(1);

    cout << answer;
    return 0;
}