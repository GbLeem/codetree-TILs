#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> ans;

void Print()
{
    int sum = 0;
    for(const auto & a : ans)
    {
        sum += a;
    }
    if(sum == m)
    {
        for(const auto & a : ans)
        {
            cout << a << " ";
        }
        cout <<"\n";
    }
}

void Choose(int cur)
{
    if(cur == n + 1)
    {
        Print();
        return;
    }
    
    for(int i = 1; i <= 6; ++i)
    {
        ans.push_back(i);
        Choose(cur + 1);
        ans.pop_back();
    }
}
int main() 
{
    cin >> n >> m;

    Choose(1);

    return 0;
}