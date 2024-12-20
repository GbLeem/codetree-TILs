#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int fire[100'002];
int office[100'002];
int answer = 0;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> fire[i];
    }
    sort(fire, fire + n);

    for (int i = 0; i < m; ++i)
    {
        cin >> office[i];
    }
    sort(office, office + m);
    int en = 0;

    //office
    for (int st = 0; st < m; ++st)
    {
        //fire
        while (en < n)
        {
            if (st < m - 1)
            {
                if (abs(office[st] - fire[en]) < abs(office[st + 1] - fire[en]))
                {                
                    answer = max(answer, abs(office[st] - fire[en]));
                    en++;
                }
                else
                    break;
            }
            //마지막
            else
            {
                answer = max(answer, abs(office[m - 1] - fire[en]));
                en++;
            }
        }
    }
    cout << answer;

    return 0;
}