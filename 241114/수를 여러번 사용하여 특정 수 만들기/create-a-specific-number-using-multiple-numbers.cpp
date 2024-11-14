#include <iostream>
using namespace std;

int A, B, C;
int answer = 0;
// int main() 
// {
//     cin >> A >> B >> C;

//     int cntA = 0;

//     while(1)
//     {
//         int cntB = 0;
//         int temp = A * cntA + B * cntB;
//         while(1)
//         {
//             temp = A * cntA + B * cntB;
//             if(temp <= C)
//                 answer = max(answer, temp);
//             if(temp > C)
//                 break;
//             cntB++;
//         }   
//         cntA++;

//         if(cntA * A > C)
//             break;
//     }

//     cout << answer;
//     return 0;
// }

int main()
{
    cin >> A >> B >> C;

    for(int i = 0; i * A <= C; ++i)
    {
        int temp = a * i; //A곱한 값

        int cnt = (C - temp) / B; //가능한 최대 B 갯수

        temp += cnt * B; //최종 값

        answer = max(answer, temp);
    }

    cout << answer;
}