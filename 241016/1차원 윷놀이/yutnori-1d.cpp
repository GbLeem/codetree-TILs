#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int board[102];

vector<int> ans;
int answer = 0;

int Count()
{
    int cnt = 0;
    int move[4];

    fill(move, move + 4, 0);

    for(int i = 0; i < ans.size(); ++i) //턴의 내용을 선택하는 인덱스
    {
        //0 0 0 2
        //1번 말이 2 4 2
        //3번 말이 4        
        move[ans[i]] += board[i];
    }

    for(int i = 0; i < k; ++i)
    {
        if(move[i] >= m -1)
            cnt++;
    }
    return cnt;
}

void Print()
{
    for(auto a : ans)
    {
        cout << a <<" ";
    }
    cout <<"\n";
}

void Choose(int cur)
{
    if(cur == n + 1)
    {
        //cout << Count()<<"\n";
        answer = max(answer, Count());
        //Print();
        return;
    }

    //최대로 고를 수 있는 인덱스
    for(int i = 0; i < k; ++i)
    {
        ans.push_back(i);        
        Choose(cur + 1);
        ans.pop_back();    
    } 
}   

int main() 
{
    cin >> n >> m >> k; //턴 수, 도착지, 말의 수

    for(int i = 0; i < n; ++i)
    {
        cin >> board[i]; //턴의 내용
        //2 4 2 4
        //0 0 0 2
        //[2+4+2] [] [4]
    }

    Choose(1);

    cout << answer;
    return 0;
}