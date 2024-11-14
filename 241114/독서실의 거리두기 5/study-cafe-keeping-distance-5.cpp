#include <iostream>
#include <string>
using namespace std;

int n;
string str;
int answer = 0;

int main()
{
    cin >> n;
    cin >> str;

    int dist = 0;

    for (int i = 0; i < str.size(); ++i)
    {
        if (dist == 0 && str[i] == '1')
        {
            dist = 1;
        }
        else if (i == str.size() - 1)
        {
            answer = max(answer, dist);
        }
        else if (dist != 0 && str[i] == '0')
        {
            dist++;
        }
        else if (dist != 0 && str[i] == '1')
        {
            answer = max(answer, dist / 2);
            dist = 1;
        }
    }

    cout << answer;
    return 0;
}