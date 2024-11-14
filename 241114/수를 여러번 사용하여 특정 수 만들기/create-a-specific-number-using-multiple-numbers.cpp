#include <iostream>
using namespace std;

int A, B, C;
int answer = 0;
int main() 
{
    cin >> A >> B >> C;

    int cntA = 0;

    while(1)
    {
        int cntB = 0;
        int temp = A * cntA + B * cntB;
        while(1)
        {
            temp = A * cntA + B * cntB;
            if(temp <= C)
                answer = max(answer, temp);
            if(temp > C)
                break;
            cntB++;
        }   
        cntA++;

        if(cntA * A > C)
            break;
    }

    cout << answer;
    return 0;
}