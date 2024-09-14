#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string bin;
    cin >> bin;
    int binary[10];
    int num = 0;

    for(int i = 0; i< bin.size(); ++i)
    {
        binary[i] = bin[i] - '0';
    }
    
    for(int i = 0; i < bin.size(); ++i)
    {
        num = num * 2 + binary[i];
    }
    
    cout << num;
    
    return 0;
}