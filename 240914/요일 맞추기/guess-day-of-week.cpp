#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int m1, d1, m2, d2;
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string weeks[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    int elapsedDays = 0;
    bool backTime = false;
    cin >> m1 >> d1 >> m2 >> d2;

    //지금 부터 x일이 지난 후의 요일은 ?
    //전으로 돌아갈 수 도 있음
    
    if(m1 > m2)
    {
        backTime = true;
        int tempM = m2;
        m2 = m1;
        m1 = tempM;

        int tempD = d2;
        d2 = d1;
        d1 = tempD;
    }

    else if(m1 == m2)
    {
        if(d1 > d2)
        {
            backTime = true;
            int temp = d2;
            d2 = d1;
            d1 = temp;
        }
    }

    while(1)
    {
        if(m1 == m2 && d1 == d2)
            break;
        
        if(d1 > days[m1])
        {
            d1 = 1;
            m1++;
        }    

        elapsedDays++;
        d1++;        
    }    
        
    
    int div = elapsedDays % 7;

    if(backTime)
        cout<< weeks[div + 5];
    else
        cout << weeks[div];


    return 0;
}