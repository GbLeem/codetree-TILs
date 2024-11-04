#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

int n, k;
int board[10'002];
unordered_map<int, set<int>> um;
vector<pair<int, int>> query(10'002);
//1 2 3 4 5

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        board[i] = i; //0 1 2 3 4 5
        um[board[i]].insert(board[i]); //1 1 , 2 2, 3 3, 4 4, 5 5  
    }

    for (int i = 1; i <= k; ++i)
    {
        int a, b;
        cin >> a >> b;  // 1 3, 1 2, 2 3, 2 4

        //인덱스
        query[i].first = a;
        query[i].second = b;
    }

    for (int i = 1; i <= 3 * k; ++i)
    {
        //새로운 인덱스의 인덱스
        int idx = i % k;        

        //새로운 인덱스
        int a = query[idx].first;
        int b = query[idx].second;

        if (idx == 0)
        {
            a = query[k].first;
            b = query[k].second;              
        }        

        swap(board[a], board[b]);
        um[board[a]].insert(b);
        um[board[b]].insert(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << um[i].size() << "\n";
    }
    return 0;
}