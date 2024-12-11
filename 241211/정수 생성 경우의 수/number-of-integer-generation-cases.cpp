#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

string str;
vector<pair<int, char>>ans;
set<string> s;
unordered_map<char, int> um;
int answer = 0;

void Print()
{
    for (auto a : ans)
    {
        cout << a.second << " ";
    }
    cout << "\n";
}
void Check()
{
    string temp;
    for(auto a : ans)
    {
        temp += a.second;
    }
    s.insert(temp);
}
void Choose(int cur)
{
    if (cur == str.size() + 1)
    {
        //끝
        //Print();
        //answer++;
        Check();
        //s.insert(ans);
        return;
    }

    //새로 들어올 값의 인덱스
    for (int i = 0; i < str.size(); ++i)
    {
        if (um[str[i]] > 0)
        {
            if (ans.size() == 1)
            {
                if (ans[0].first - 1 == i || i == ans[0].first + 1)
                {
                    ans.push_back({ i, str[i]});
                    um[str[i]]--;

                    Choose(cur + 1);

                    um[ans.back().second]++;
                    ans.pop_back();
                }
            }
            else if (ans.size() > 1)
            {
                vector<pair<int, char>> temp = ans;
                sort(temp.begin(), temp.end());

                if (temp[0].first - 1 == i || temp.back().first + 1 == i)
                {
                    ans.push_back({ i, str[i] });
                    um[str[i]]--;

                    Choose(cur + 1);

                    um[ans.back().second]++;
                    ans.pop_back();
                }
            }
            else if (ans.empty())
            {
                ans.push_back({ i, str[i] });
                um[str[i]]--;

                Choose(cur + 1);

                um[ans.back().second]++;
                ans.pop_back();
            }
        }
    }

}


int main()
{
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
    {
        um[str[i]]++;
    }


    Choose(1);
    //현재 ans의 최대 혹은 최소 index와 1 차이나는 것만 들어올 수 있음

    cout << s.size();
   
    return 0;
}