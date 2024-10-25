#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n;
int startT = 0;
int endT = 0;
int checkT = 0;

unordered_map<string, int> um;
int answer = 0;

int stringToTime(string s)
{
    int time = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(i == 2)
            continue;
        else if(i == 0)
            time += (s[i] - '0') * 10;
        else if(i == 1)
        {
            time += s[i] - '0';
            time *= 60;
        }
        else if(i == 3)
        {
            time += (s[i] - '0') * 10;
        }
        else if(i == 4)
        {
            time += (s[i] - '0');
        }
    }

    return time;
}

int main() 
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    startT = stringToTime(s1);
    endT = stringToTime(s2);
    checkT = stringToTime(s3);

    cin >> n;

    for(int i = 0; i < n ;++i)
    {
        string str1, str2;
        cin >> str1 >> str2;

        int time = stringToTime(str1);
        string name = str2;

        //없을 때
        if(um.find(name) == um.end())
        {
            //시작 조건 
            if(time <= startT)
                um.insert({name, 1});
            //종료 조건
            if(endT <= time && time <= checkT)
            {
                um.insert({name, 2});
            }
        }
        else //찾은 경우
        {
            //시작 조건인 경우
            if(um[name] == 1)
            {
                if(endT <= time && time <= checkT)
                {
                    um[name] = 3;
                    answer++;
                }                
                
            }
            else if(um[name] == 2)
            {
                if(time <= startT)
                {
                    um[name] = 3;
                    answer++;
                }
            }
        }
    }

    cout<< answer;

    return 0;
}