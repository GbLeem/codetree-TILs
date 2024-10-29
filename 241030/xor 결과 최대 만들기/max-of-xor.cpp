#include <iostream>
#include <vector>
using namespace std;

int n, m;
int board[22];
vector<int> ans;
bool isused[1'000'002];
int answer = 0;

int Check()
{
    int temp = ans[0];
    if(ans.size() == 1)
        return temp;
    for(int i = 1; i < ans.size(); ++i)
    {
        temp = temp^ans[i];
    }

    return temp;
}

void Print()
{
    for(auto a : ans)
    {
        cout << a << " ";
    }
    cout <<"\n";
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
        if(!isused[board[i]])
        {
            ans.push_back(board[i]);
            isused[board[i]] = true;
            Choose(cur + 1);
            ans.pop_back();
            isused[board[i]] = false;
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