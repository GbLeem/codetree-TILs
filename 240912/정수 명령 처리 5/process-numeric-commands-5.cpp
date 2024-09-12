#include <iostream>
#include <vector>
using namespace std;



int main() 
{
    int n; 
    cin >> n;

    vector<int> vec;
    int vecSize = 0;
    for(int i = 0; i < n; ++i)
    {
        string str;
        int value;

        cin >> str;

        if(str == "push_back")
        {
            cin >> value;
            vecSize++;
            vec.push_back(value);
        }
        else if(str == "get")
        {
            cin >> value;
            cout << vec[value - 1]<<"\n";
        }
        else if(str == "size")
        {
            cout << vecSize<<"\n";
        }
        else if(str == "pop_back")
        {
            vec.pop_back();
            vecSize--;
        }
    }

    return 0;
}