#include <iostream>
#include <unordered_set>
using namespace std;

int n, k;
int board[100'002];
pair<int, int> query[100'002];
unordered_set<int> us[100'002];

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        board[i] = i;
        us[i].insert(i);
    }

    for (int i = 0; i < k; ++i)
    {
        int a, b;
        cin >> a >> b;
        query[i] = { a, b };
    }


    for (int i = 0; i < 3 * k; ++i)
    {
        int a = query[i % k].first;
        int b = query[i % k].second;

        us[board[a]].insert(b);
        us[board[b]].insert(a);
        swap(board[a], board[b]);
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << us[i].size() << "\n";
    }
    return 0;
}