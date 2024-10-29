#include <iostream>
#include <vector>
using namespace std;

int n, m;
int board[22];
vector<int> ans;
bool isused[22];
int answer = 0;

int Check()
{
    int temp = ans[0];
    for(int i = 1; i < ans.size(); ++i)
    {
        temp = temp^ans[i];
    }

    return temp;
}

void Choose(int cur)
{
    if(cur == m + 1)
    {
        answer = max(answer, Check());
        return;
    }
    for(int i = 0; i < n; ++i)
    {
        if(!isused[i])
        {
            ans.push_back(i);
            isused[i] = true;
            Choose(cur + 1);
            ans.pop_back();
            isused[i] = false;
        }
    }
}
int main() 
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> board[i];

    Choose(1);
    cout << answer;    

   
    return 0;
}