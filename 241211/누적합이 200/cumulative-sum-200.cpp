#include <iostream>
using namespace std;

int n;
int sum = 0;
int cnt = 0;
int answer = 0;

int main() 
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        sum += num;
        cnt++;

        if(sum > 200)
            break;
    }

    cout << fixed;
    cout.precision(1);

    cout << sum <<"\n" << (float)sum/cnt;
    return 0;
}