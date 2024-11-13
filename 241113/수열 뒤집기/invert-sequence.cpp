#include <iostream>
#include <vector>
using namespace std;

int n, k;
int a1, a2;
int b1, b2;
int board[102];
vector<vector<int>> vec;

void Change(vector<int>& before, int st, int en)
{
    vector<int> tempBoard(n + 1);
    int end = en;

    for (int i = st; i <= en; ++i)
    {
        tempBoard[i] = before[end];
        end--;
    }
    for (int i = st; i <= en; ++i)
    {
        before[i] = tempBoard[i];            
    }
}

int main()
{
    cin >> n >> k;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    vector<int> temp(n + 1);

    for (int i = 1; i <= n; ++i)
        temp[i] = i;
    vec.push_back(temp); // 1 2 3 4 5 6 7

    while (1)
    {
        Change(temp, a1, a2);
        Change(temp, b1, b2);        
        vec.push_back(temp);

        if (temp == vec.front())
            break;
    }

    vector<int> ans = vec[k];

    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}