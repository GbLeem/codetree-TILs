#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string str;
int answer = 0;

int main() 
{
    cin >> str;

    for(int i = str.size() - 1; i >= 0; --i)
    {
        answer += (str[i] - '0') * pow(2, i);
    }

    cout << answer;
    return 0;
}