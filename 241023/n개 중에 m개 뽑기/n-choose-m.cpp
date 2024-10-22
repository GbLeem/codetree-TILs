#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> ans;
bool isused[12];

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
        Print();
        return ;
    }

    for(int i = 1; i <= n; ++i)
    {
        if(!isused[i])
        {            
            if(ans.empty() || (!ans.empty() && ans.back() < i))
            {
                ans.push_back(i);
                isused[i] = true;
                Choose(cur + 1);
                ans.pop_back();  
                isused[i] = false;             
            }
        }
    }

}
int main() 
{
    cin >> n >> m;

    Choose(1);
    return 0;
}