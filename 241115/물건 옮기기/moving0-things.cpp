#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> vec(12);
int answer = 0;

void Print()
{
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[i].size(); ++j)
        {
            cout << vec[i][j] <<" ";
        }
        cout << "\n";
    }
}

int main() 
{
    cin >> n;    

    for(int i = 0; i < n; ++i)
    {
        int num, pos;
        cin >> num >> pos;

        vec[num].push_back(pos);
    }

    //Print();
    for(int i = 0; i < vec.size(); ++i)
    {
        int last = -1;
        int cnt = 0;
        for(int j = 0; j < vec[i].size(); ++j)
        {
            //처음 처리
            if(last == -1)
            {
                if(vec[i][j] == 1)
                    last = 1;
                else if(vec[i][j] == 0)
                    last = 0;
            }
            else
            {
                if(last == 1)
                {
                    if(vec[i][j] == 0)
                    {
                        cnt++;
                        last = 0;
                    }
                }
                else if(last == 0)
                {
                    if(vec[i][j] == 1)
                    {
                        cnt++;
                        last = 1;
                    }
                }
            }            
        }        
        answer += cnt;
    }
    cout << answer;
    return 0;
}