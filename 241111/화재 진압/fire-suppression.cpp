#include <iostream>
#include <climits>
using namespace std;

int n, m;
int fire[100'002];
int office[100'002];
int answer = 0;
int main() 
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        cin >> fire[i]; //가능성
    }

    for(int i = 0; i < m; ++i)
    {
        cin >> office[i];
    }

    int en = 0;
    int temp = INT_MAX;
    
    //office
    for(int st = 0; st < m; ++st)
    {   
        //fire
        if(st == m - 1)
        {
            answer = abs(office[st]-fire[n-1]);
        }
        else
        {
            while(en < n && abs(office[st] - fire[en]) <= abs(office[st + 1] - fire[en]))
            {
                answer = max(answer, office[en] - fire[st]);
                en++;
            }
        }
    }
    cout << answer;
    return 0;
}