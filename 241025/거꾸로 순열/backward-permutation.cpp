#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
bool isused[10];
int n;


void Print()
{
    for(auto a : ans)
        cout << a << " ";
    cout <<"\n";
}
void Choose(int cur)
{
    if(cur == n + 1)
    {
        Print();
        return;
    }

    for(int i = n; i >= 1; --i)
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
    cin >> n;   

    Choose(1);

    return 0;
}