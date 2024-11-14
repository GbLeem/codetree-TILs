#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string str;
int answer = 0;

int main() 
{
    cin >> str;

    for(int i = 0; i < str.size(); ++i)
    {
        answer += (str[i] - '0') * pow(2, str.size()-i-1);
    }

    cout << answer;
    return 0;
}