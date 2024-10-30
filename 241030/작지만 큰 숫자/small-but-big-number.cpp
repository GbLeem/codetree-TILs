#include <iostream>
#include <set>
using namespace std;

set<int> s;
int n, m;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        s.insert(num);
    }
    //3 5 7 8 9

    for (int i = 0; i < m; ++i)
    {
        int num;
        cin >> num;

        if (*s.lower_bound(num) == num)
        {
            cout << num << "\n";
            s.erase(num);
        }
        else
        {
            if (--s.lower_bound(num) == --s.begin())
            {
                cout << -1 << "\n";           
            }

            else
            {
                int temp = *(--s.lower_bound(num));
                cout << temp << "\n";
                s.erase(temp);
            }
        }
    }

    return 0;
}