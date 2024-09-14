#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int m1, d1, m2, d2;
    string week;

    int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string weeks[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    int elapsedDays = 0;

    cin >> m1 >> d1 >> m2 >> d2;
    cin >> week;

    while(1)
    {
        if(m1 == m2 && d1 == d2)
            break;
        
        elapsedDays++;
        d1++;
        
        if(d1 > days[m1])
        {
            d1 = 1;
            m1++;
        }
    }

    int index = 0;
    while(1)
    {
        if(weeks[index] == week)
            break;
        index++;
    }

    // elaspsedDays를 7로 나눈 나머지가 index인 숫자의 갯수
    int answer = 0;
    while(1)
    {
        if(elapsedDays == 0)
            break;
        if(elapsedDays % 7 == index)
            answer++;
        elapsedDays--;
    }
    
    cout << answer;
    return 0;
}