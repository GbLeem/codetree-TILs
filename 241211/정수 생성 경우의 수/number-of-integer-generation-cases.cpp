#include <iostream>
#include <cmath>
using namespace std;

string str;
int n;
int answer = 0;

int main() 
{
    cin >> str;
    n = str.size();
    answer = pow(2, n - 1);    
    
    //연속된 숫자 
    int temp = 0;

    for(int i = 0; i < str.size() - 1; ++i)
    {
        if(str[i] == str[i + 1])
        {
            temp++;
        }
        else
        {
            if(temp != 0)
            {
                answer -= pow(2, temp);
                temp = 0;
            }
        }
    }
    
    if(temp != 0)
    {
        answer -= pow(2, temp);
        temp = 0;
    }




    cout << answer;


    return 0;
}