#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q1;
queue<int> q2;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b; 
}

int main() 
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        q1.push(num); // 2 5
        q2.push(num);
    }

    int g = 0;
    int l = 0;

    while(!q1.empty())
    {
        int a = q1.front();
        q1.pop();
        if(q1.empty())
        {
            cout << a <<" ";
            break;
        }
        int b = q1.front();
        q1.pop();

        g = gcd(a, b);
        q1.push(g);
    }

    while(!q2.empty())
    {
        int a = q2.front();
        q2.pop();
        if(q2.empty())
        {
            cout << a <<" ";
            break;
        }
        int b = q2.front();
        q2.pop();

        l = lcm(a, b);
        q2.push(l);
    }


    return 0;
}