#include <iostream>
#include <climits>
using namespace std;

int board[102];
int answer = INT_MAX;

int main()
{
    //최소 t번 이상 h높이가 되도록
    int n, h, t;
    cin >> n >> h >> t;

    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    for (int i = 0; i < n - t + 1; ++i)
    {
        int cnt = 0;
        int temp = 0;

        for (int j = i; j < n; ++j)
        {
            //차이
            int cost = abs(h - board[j]);
            //비용 
            temp += cost;
            //연속 횟수 체크
            cnt++;

            if (cnt == t)
                break;
        }

        answer = min(answer, temp);
    }

    cout << answer;
    return 0;
}