#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() 
{
    int num = 0;
    int multiply = 0;
    pair<int, int> index = {15, 0}; //가장 작은 인덱스, mul 저장

    string str;
    cin >> str;

    for(int i = str.size() - 1; i >= 0; --i)
    {
        if(str[i] == '0')    
            index = {i, multiply};    
        else
            num += pow(2, multiply);

        multiply++;        
    }

    if(index.first != 15)
    {
        num += pow(2, index.second);
    }
    else
    {
        num -= 1;
    }
    cout << num;
    return 0;
}