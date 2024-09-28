#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int digits[100000];
int cnt = 0;

//10진수 n을 b진수로 바꾸기
void makeB(int n, int B)
{
    while (true) 
    {
        if(n < B) 
        {
            digits[cnt++] = n;
            break;
        }

        digits[cnt++] = n % B;
        n /= B;
    }
    
    //출력하기
    for(int i = cnt - 1; i >= 0; i--)
        cout << digits[i];
}

int main() 
{
    int a, b;
    int n;
    int num = 0;

    cin >> a >> b;
    cin >> n;

    string str = to_string(n);    
    
    int mult = 0;
    //a진수의 숫자 n을 10진수로 바꾸기
    for(int i = str.size() - 1; i >= 0; --i)
    {
        num += pow(a, mult) * (str[i] - '0');
        mult++;
    }

    makeB(num, b);
    return 0;
}