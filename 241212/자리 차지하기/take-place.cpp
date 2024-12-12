#include <iostream>
#include <set>
using namespace std;

int n, m;
set<int> s;
int board[100'002];
int answer = 0;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
    }

    for (int i = 1; i <= m; ++i)
    {
        s.insert(i); //1 2 3 4 5
    }

    for (int i = 0; i < n; ++i)
    {
        auto it = s.lower_bound(board[i]);

        if (it != s.end())
        {
            if (*it == board[i])
            {
                s.erase(*it);
                answer++;
            }
            else
            {
                if (it != s.begin())
                {
                    --it;
                    s.erase(*it);
                    answer++;
                }
                else
                    break;
            }
        }
        else
        {
            it--;
            s.erase(*it);
            answer++;
        }
    }
    cout << answer;
    return 0;
}