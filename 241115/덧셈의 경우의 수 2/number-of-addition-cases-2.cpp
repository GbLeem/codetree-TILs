#include <iostream>
#include <vector>
using namespace std;

int n, k;
int board[1002];
int answer = 0;
vector<int> ans;

bool Check()
{
    int temp = 0;
    for(auto a: ans)
    {
        temp += a;
    }
    
    if(temp == n)
        return true;
    return false;
}

void Choose(int cur)
{
    if(cur == k + 1)
    {
        if(Check())
            answer++;
        return ;
    }
    for(int i = 0; i <= n; ++i)
    {
        ans.push_back(i);
        Choose(cur + 1);
        ans.pop_back();
    }
}

int main() 
{
    cin >> n >> k; // 20 2

    for(int i = 0; i <= n; ++i)
    {
        cin >> board[i]; //0 ~ 20
    }

    Choose(1);

    //0 ~ 20 까지 수 두개 뽑아서 20 만들기
    
    cout << answer;

    return 0;
}