#include <iostream>
#include <vector>
using namespace std;

int n, k;
bool isused[12];
vector<int> ans;
vector<vector<int>> vec;
vector<int> board;

void Print()
{
    for(auto v : vec)
    {
        for(auto vi : v)
        {
            cout << vi <<" ";
        }
        cout <<"\n";
    }
    cout<<"\n";
}

void Choose(int cur)
{
    if(cur == k + 1)
    {
        vec.push_back(ans);
        return ;
    }   

    for(int i = 1; i <= n; ++i)
    {
        if(!isused[i])
        {
            if(ans.empty() || ans.back() < i)
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
    cin >> n >> k;

    for(int i = 0; i < k; ++i)
    {
        int num;
        cin >> num;
        board.push_back(num); // 2 3 4
    }

    Choose(1);

    for(int i = 0; i < vec.size(); ++i)
    {       
        int same = true;
        for(int j = 0; j < k; ++j)
        {
            if(vec[i][j] != board[j])
                same = false;            
        }

        if(same)
        {            
            if(i + 1 <= vec.size() - 1)
            {
                for(auto a : vec[i + 1])
                {
                    cout << a << " ";
                }
                cout <<"\n";
                return 0;
            }
        }
    }

    cout << "NONE";
    return 0;
}