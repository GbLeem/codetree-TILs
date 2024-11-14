#include <iostream>
using namespace std;

int A, B, C;
int answer = 0;

int main()
{
    cin >> A >> B >> C;

    for(int i = 0; i * A <= C; ++i)
    {
        int temp = A * i; //A곱한 값

        int cnt = (C - temp) / B; //가능한 최대 B 갯수

        temp += cnt * B; //최종 값

        answer = max(answer, temp);
    }

    cout << answer;
}