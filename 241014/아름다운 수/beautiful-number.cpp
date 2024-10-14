#include <iostream>
#include <vector>
using namespace std;

int n;
int cnt = 0;
vector<int> ans;

void Print()
{
    for(int i = 0; i <ans.size(); ++i)
    {
        cout << ans[i] <<" ";
    }
    cout <<"\n";
}

//현재 자리 cur
void Choose(int cur)
{
    if(cur == n + 1)
    {
        //초기화        
        int temp = ans[0]; //처음에 선택
        int c = 1;//연속해서 몇개인지                
        
        for(int i = 1; i < ans.size(); ++i)
        {
            if(temp == ans[i])
                c++;
            else if(temp != ans[i])
            {
                //연속된 갯수가 해당 숫자만큼 반복 안된 경우
                //아름다운 수가 아님
                if(c % temp != 0)
                {                 
                    return ;                    
                }           
                c = 1;
                temp = ans[i];                            
            }
        }        
        if(c % temp == 0)        
            cnt++;       

        return;
    }

    for(int i = 1; i <= 4; ++i)
    {
        ans.push_back(i);
        Choose(cur + 1);
        ans.pop_back();
    }
}


int main() 
{
    cin >> n;

    Choose(1);
    cout << cnt;
    
    return 0;
}