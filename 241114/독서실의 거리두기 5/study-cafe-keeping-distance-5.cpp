#include <iostream>
#include <string>
#include <climits>
using namespace std;

int n;
string str;
int answer = 0;

int main()
{
    cin >> n;
    cin >> str;

    for (int i = 0; i < str.size(); ++i) //새로 들어갈 자리
    {
        if(str[i] == '1')
            continue;
        else //0인 경우
        {
            str[i] = '1';
            int dist = 0;
            int minDist = INT_MAX;

            for(int j = 0; j < str.size(); ++j)
            {
                //맨 처음
                if (dist == 0 && str[j] == '1')
                {
                    dist = 1;
                }                
                else if (dist != 0 && str[j] == '0')
                {
                    dist++;
                }
                else if (dist != 0 && str[j] == '1')
                {
                    minDist = min(minDist, dist);
                    dist = 1;
                }
            }
            //다시 돌려주기
            str[i] = '0';
            answer = max(answer, minDist);
        }
    }

    cout << answer;
    return 0;
}