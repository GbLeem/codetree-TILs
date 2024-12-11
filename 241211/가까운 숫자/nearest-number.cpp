#include <iostream>
#include <set>
#include <climits>
using namespace std;

int n;
set<int> s;
int answer = INT_MAX;

int main() 
{
    cin >> n;    
    s.insert(0);

    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        s.insert(num); //0 3

        auto big = s.upper_bound(num);

        if(big != s.end())
        {
            //cout <<"큰값 " <<*big <<"\n";
            answer = min(answer, abs(*big - num));
        }
        big--;
        big--;
        //cout << "작은값 " << *big <<"\n";
        answer = min(answer, abs(*big - num));
        

        cout << answer <<"\n";
    }


    return 0;
}