#include <iostream>
using namespace std;

int x, y;
int answer = 0;

int main()
{
    cin >> x >> y;

    for (int i = x; i <= y; ++i)
    {
        int div = 10;
        int tempAns = 0;
        int tempValue = i;

        while (tempValue > 0)
        {            
            tempAns += tempValue % div;
            tempValue /= div;
        }

        answer = max(answer, tempAns);
    }

    cout << answer;

    return 0;
}