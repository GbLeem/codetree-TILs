#include <iostream>
using namespace std;

int n, m;
int boardA[100'002];
int boardB[100'002];

int main() 
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> boardA[i];
    for(int i = 0; i < m; ++i)
        cin >> boardB[i];

    //B가 A의 부분수열

    int en = 0;

    for(int st = 0; st < m; ++st) //B
    {
        while(en < n && boardA[en] != boardB[st])
        {            
            en++;
        }

        //못찾음
        if(en == n) 
        {
            cout << "No";
            return 0;
        }        
    }
    cout <<"Yes";

    return 0;
}